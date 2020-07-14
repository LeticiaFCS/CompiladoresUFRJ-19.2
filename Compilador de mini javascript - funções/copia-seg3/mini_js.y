%{
#include <string>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

struct Atributos {
	vector<string> v;
	int id;
};

#define YYSTYPE Atributos

#define st first
#define nd second

#define jump "#"
#define get "@"
#define set "="
#define jumpTrue "?"
#define let "&"
#define getProp "[@]"
#define setProp "[=]"
#define callFunc "$"
#define retFunc "~"
#define pop "^"
#define halt "."

void erro( string msg );
void New_Inst( string st ); //nova instrução
void New_Inst( vector<string> &st );

void New_FInst( string st ); //nova instrução dentro de funcao
void New_FInst( vector<string> &st );

void New_Line();

void New_Func_Line();

void imprime_codigo();
void get_var(vector<string> v);
void let_var(vector<string> v);
string gera_ini_label(string pref,int id);
string gera_fim_label(string pref,int id);
int get_id();
int get_func_id();
// protótipo para o analisador léxico (gerado pelo lex)
int yylex();
void yyerror( const char* );
int retorna( int tk );

int linha = 1;
int coluna = 1;


vector<string> codigo;
vector<string> func_codigo;
map<string,int> var_globais;

vector<string> operator+( vector<string> a, vector<string> b ) {
	a.insert( a.end(), b.begin(), b.end() );
	return a;
}

vector<string> operator+( vector<string> a, string b ) {
	a.push_back(b);
	return a;
}
vector<string> operator+( string a, vector<string> b ) {
	return b+a;
}

%}

%token NUM NEGNUM STR ID LET NEWOBJ NEWARRAY IF ELSE IGUAL MAI_IG MEN_IG RETURN FUNCTION

%left '.'
%left '+' '-'
%left '*' '/' '%'

%right '='


%%


START : CMD
      ;

CMD : LET Decl CMD
	| P CMD
	| IF_LINHA CMD
	|ID '('PARAM_CHA')' {New_Inst($1.v); New_Inst(get); New_Inst(callFunc);} ';' {New_Line();}CMD
	| FUNCTION ID{ 
	  
	   let_var($2.v);
	
	   New_Inst( $2.v ); 
	   New_Inst(let); 
	   New_Inst( $2.v );
	   New_Inst("{}");
	   New_Inst(set);
	   New_Inst("'&funcao'");
	   $1.id=get_func_id();
	   New_Inst(gera_ini_label("FUNC",$1.id));
	   New_Inst(setProp);
	   New_Inst(pop);
	   New_Line();
	   New_FInst(gera_fim_label("FUNC",$1.id));
	   New_Func_Line();
	  } '(' PARAM_FUN ')'  '{' CMD_FUN '}' 
	   {New_Line();}CMD
	  |
	;


CMD_LINHA : A';'
          | LET Decl
          | IF_LINHA CMD
          ;
BLOCO: CMD_LINHA
	 | '{' CMD '}'
	 |
	 ;

IF_LINHA : IF '('COND')' {$1.id=get_id();}
           {New_Inst(gera_ini_label("INI_IF",$1.id));New_Inst(jumpTrue);
           New_Line();
           New_Inst(gera_ini_label("ELSE_IF",$1.id));New_Inst(jump);
           New_Line();
           New_Inst(gera_fim_label("INI_IF",$1.id));}
           BLOCO 
           {New_Inst(gera_ini_label("FIM_IF",$1.id));New_Inst(jump);}
           ELSE_LINHA 
           {New_Inst(gera_fim_label("ELSE_IF",$1.id));}
           BLOCO{New_Inst(gera_fim_label("FIM_IF",$1.id));} 
         ;

ELSE_LINHA:
		  |ELSE
		  ;

Decl : ID { New_Inst( $1.v ); let_var($1.v); New_Inst(let); New_Line();} ',' Decl
	 | ID { New_Inst( $1.v ); let_var($1.v); New_Inst(let); New_Line();} ';' 
	 | Adecl ',' Decl
	 | Adecl ';'
	 ;
	 
Adecl : ID { New_Inst( $1.v ); let_var($1.v); New_Inst(let); New_Inst( $1.v ); }'=' RVALUE { New_Inst( set ); New_Inst( pop ); New_Line(); }
	  ;

P : A ';' P
	| A ';'
	;

A : ID { New_Inst( $1.v ); get_var($1.v);} '=' RVALUE { New_Inst( set ); New_Inst( pop ); New_Line(); }
  | LVALUEPROP '=' RVALUE { New_Inst( setProp ); New_Inst( pop ); New_Line(); }
  ;

LVALUEPROP : E '.' LVALUEPROPSUFFIX
		   | E'['E']''.'{New_Inst(getProp);}LVALUEPROPSUFFIX
		   | E'['E']'
		   ;
LVALUEPROPSUFFIX: ID { New_Inst( $1.v );}
				| ID { New_Inst( $1.v );}{New_Inst(getProp);}'['ELPROP']'
				| ID { New_Inst( $1.v );}'.'{New_Inst(getProp);}LVALUEPROPSUFFIX
				| ID { New_Inst( $1.v );}'.'{New_Inst(getProp);}LVALUEPROPSUFFIX'['ELPROP']'
				;
				

RVALUE : E
	   | NEWOBJ {New_Inst("{}");}
	   | NEWARRAY {New_Inst("[]");}
	   | A { New_Inst( $1.v ); get_var($1.v); New_Inst(get);}
	   | ID '('PARAM_CHA')' {New_Inst($1.v); New_Inst(get); New_Inst(callFunc);}
	   ;
E : E '+' E { New_Inst( "+" ); }
	| E '-' E { New_Inst( "-" ); }
	| E '*' E { New_Inst( "*" ); }
	| E '/' E { New_Inst( "/" ); }
	| E '%' E { New_Inst( "%" ); }
	| F
	;

COND : E '<' E { New_Inst( "<" ); }
     | E '>' E { New_Inst( ">" ); }
     | E IGUAL E { New_Inst( "==" ); }
     | E MAI_IG E { New_Inst( ">=" ); }
     | E MEN_IG E { New_Inst( "<=" ); }
     ;

ELPROP: ELPROP '+' ELPROP { New_Inst( "+" ); }
	  | ELPROP '-' ELPROP { New_Inst( "-" ); }
      | ELPROP '*' ELPROP { New_Inst( "*" ); }
	  | ELPROP '/' ELPROP { New_Inst( "/" ); }
	  | ELPROP '%' ELPROP { New_Inst( "%" ); }
	  | FLPROP
	  ;

FLPROP: ID { New_Inst( $1.v ); }
		| NUM { New_Inst(	$1.v ); }
		| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_Inst("0"); New_Inst($1.v[sz] ); New_Inst("-");}
		| STR { New_Inst(	$1.v ); }
		| '(' RVALUE ')'
		| ID '(' PARAM_CHA ')' { New_Inst( $1.v ); New_Inst(jump) ;}
		;
	
	
F : ID { New_Inst( $1.v ); get_var($1.v); New_Inst(get); }
	| NUM { New_Inst(	$1.v ); }
	| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_Inst("0"); New_Inst($1.v[sz] ); New_Inst("-");}
	| STR { New_Inst(	$1.v ); }
	| '(' RVALUE ')'
	| LVALUEPROP {New_Inst(getProp);}
	;
	
	
PARAM_CHA : ARGs_CHA {New_Inst(to_string($$.id));}
	  | {New_Inst("0");}
	  ;
	
ARGs_CHA : RVALUE',' ARGs_CHA {$$.id=1+$3.id;}
	 | RVALUE {$$.id=1;}
	 ;	
	
PARAM_FUN : ARGs_FUN 
	  | 
	  ;
ARGs_FUN : ID ',' ARGs_FUN
	 | ID {
	 		int arg_num=0;
			for(int i=3;i<$1.v.size();i++){
				auto k =$1.v[i];
				if(k!=","){
					vector<string> new_variable;
					new_variable.push_back(k);
					let_var(new_variable);
					New_FInst(k);
					New_FInst(let);
					New_FInst(k);
					New_FInst("arguments");
					New_FInst(get);
					New_FInst(to_string(arg_num++));
					New_FInst(getProp);
					New_FInst(set);
					New_FInst(pop);
					New_Func_Line();				
				}
			}
		}
	 ;

//Gramatica de funcoes

CMD_FUN : LET Decl_FUN CMD_FUN
	| P_FUN CMD_FUN
	| IF_LINHA_FUN CMD_FUN
	| RETURN RVALUE_FUN {
	New_FInst("'&retorno'"); New_FInst(get); New_FInst(retFunc);
	New_Func_Line();
	}';' CMD_FUN;
	| {
	     New_FInst("undefined"); New_FInst(get); New_FInst("'&retorno'"); New_FInst(get); New_FInst(retFunc);
	     New_Func_Line();
	  }
	;


CMD_FUN_LINHA_FUN : A_FUN';'
          | LET Decl_FUN
          | IF_LINHA_FUN CMD_FUN
          | RETURN RVALUE_FUN {
	New_FInst("'&retorno'"); New_FInst(get); New_FInst(retFunc);
	New_Func_Line();
	}';'
          ;
BLOCO_FUN: CMD_FUN_LINHA_FUN
	 | '{' CMD_FUN '}'
	 |
	 ;

IF_LINHA_FUN : IF '('COND_FUN')' {$1.id=get_id();}
           {New_FInst(gera_ini_label("INI_IF",$1.id));New_FInst(jumpTrue);
           New_Func_Line();
           New_FInst(gera_ini_label("ELSE_IF",$1.id));New_FInst(jump);
           New_Func_Line();
           New_FInst(gera_fim_label("INI_IF",$1.id));}
           BLOCO_FUN 
           {New_FInst(gera_ini_label("FIM_IF",$1.id));New_FInst(jump);}
           ELSE_LINHA_FUN 
           {New_FInst(gera_fim_label("ELSE_IF",$1.id));}
           BLOCO_FUN{New_FInst(gera_fim_label("FIM_IF",$1.id));} 
         ;

ELSE_LINHA_FUN:
		  |ELSE
		  ;

Decl_FUN : ID { New_FInst( $1.v ); let_var($1.v); New_FInst(let); New_Func_Line();} ',' Decl_FUN
	 | ID { New_FInst( $1.v ); let_var($1.v); New_FInst(let); New_Func_Line();} ';' 
	 | Adecl_FUN ',' Decl_FUN
	 | Adecl_FUN ';'
	 ;
	 
Adecl_FUN : ID { New_FInst( $1.v );let_var($1.v); New_FInst(let); New_FInst( $1.v ); }'=' RVALUE_FUN { New_FInst( set ); New_FInst( pop ); New_Func_Line(); }
	  ;

P_FUN : A_FUN ';' P_FUN
	| A_FUN ';'
	;

A_FUN : ID { New_FInst( $1.v ); get_var($1.v);} '=' RVALUE_FUN { New_FInst( set ); New_FInst( pop ); New_Func_Line(); }
  | LVALUEPROP_FUN '=' RVALUE_FUN { New_FInst( setProp ); New_FInst( pop ); New_Func_Line(); }

  ;

LVALUEPROP_FUN : E_FUN '.' LVALUEPROP_FUNSUFFIX
		   | E_FUN'['E_FUN']''.'{New_FInst(getProp);}LVALUEPROP_FUNSUFFIX
		   | E_FUN'['E_FUN']'
		   ;
LVALUEPROP_FUNSUFFIX: ID { New_FInst( $1.v );}
				| ID { New_FInst( $1.v );}{New_FInst(getProp);}'['ELPROP_FUN']'
				| ID { New_FInst( $1.v );}'.'{New_FInst(getProp);}LVALUEPROP_FUNSUFFIX
				| ID { New_FInst( $1.v );}'.'{New_FInst(getProp);}LVALUEPROP_FUNSUFFIX'['ELPROP_FUN']'
				;
				

RVALUE_FUN : E_FUN
	   | NEWOBJ {New_FInst("{}");}
	   | NEWARRAY {New_FInst("[]");}
	   | A_FUN { New_FInst( $1.v ); get_var($1.v); New_FInst(get);}
	   | ID '('PARAM_CHA_FUN')' {New_FInst($1.v); New_FInst(get); New_FInst(callFunc);}
	   ;
E_FUN : E_FUN '+' E_FUN { New_FInst( "+" ); }
	| E_FUN '-' E_FUN { New_FInst( "-" ); }
	| E_FUN '*' E_FUN { New_FInst( "*" ); }
	| E_FUN '/' E_FUN { New_FInst( "/" ); }
	| E_FUN '%' E_FUN { New_FInst( "%" ); }
	| F_FUN
	;

COND_FUN : E_FUN '<' E_FUN { New_FInst( "<" ); }
     | E_FUN '>' E_FUN { New_FInst( ">" ); }
     | E_FUN IGUAL E_FUN { New_FInst( "==" ); }
     | E_FUN MAI_IG E_FUN { New_FInst( ">=" ); }
     | E_FUN MEN_IG E_FUN { New_FInst( "<=" ); }
     ;

ELPROP_FUN: ELPROP_FUN '+' ELPROP_FUN { New_FInst( "+" ); }
	  | ELPROP_FUN '-' ELPROP_FUN { New_FInst( "-" ); }
      | ELPROP_FUN '*' ELPROP_FUN { New_FInst( "*" ); }
	  | ELPROP_FUN '/' ELPROP_FUN { New_FInst( "/" ); }
	  | ELPROP_FUN '%' ELPROP_FUN { New_FInst( "%" ); }
	  | FLPROP_FUN
	  ;

FLPROP_FUN: ID { New_FInst( $1.v ); }
		| NUM { New_FInst(	$1.v ); }
		| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_FInst("0"); New_FInst($1.v[sz] ); New_FInst("-");}
		| STR { New_FInst(	$1.v ); }
		| '(' RVALUE_FUN ')'
		| ID '(' PARAM_CHA_FUN ')' { New_FInst( $1.v ); New_FInst(jump) ;}
		;
	
	
F_FUN : ID { New_FInst( $1.v ); get_var($1.v); New_FInst(get); }
	| NUM { New_FInst(	$1.v ); }
	| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_FInst("0"); New_FInst($1.v[sz] ); New_FInst("-");}
	| STR { New_FInst(	$1.v ); }
	| '(' RVALUE_FUN ')'
	| LVALUEPROP_FUN {New_FInst(getProp);}
	;
	
PARAM_CHA_FUN : ARGs_CHA_FUN {New_Inst(to_string($$.id));}
	  | 
	  ;
	
ARGs_CHA_FUN : RVALUE_FUN',' ARGs_CHA_FUN {$$.id=1+$3.id;}
	 | RVALUE_FUN {$$.id=1;}
	 ;	
	

%%

#include "lex.yy.c"

map<int,string> nome_tokens = {
	{ STR, "string" },
	{ ID, "nome de identificador" },
	{ NUM, "número" }
};

string nome_token( int token ) {
	if( nome_tokens.find( token ) != nome_tokens.end() )
		return nome_tokens[token];
	else {
		string r;
		
		r = token;
		return r;
	}
}

int retorna( int tk ) {	
	yylval.v.push_back(yytext); 
	coluna += strlen( yytext ); 

	return tk;
}

void yyerror( const char* msg ) {
	cerr << msg << endl;
	exit( 1 );
}



void New_Line(){
	codigo.push_back("\n");
}

void New_Func_Line(){
	func_codigo.push_back("\n");
}

void imprime_codigo(vector<string> &codigo){
	int cont=0;
	for(unsigned int i=0;i<codigo.size();i++){
		//if(codigo[i]!="\n")
			//cerr<<cont++<<":";
		cout<<codigo[i];
		if(codigo[i]!="\n")
			cout<<' ';
	}
}

void get_var(vector<string> v){
	string w = v[v.size()-1];
	if(var_globais.count(w)==0){
		string msg = "Erro: a variável '"+w+"' não foi declarada.";
		yyerror(msg.c_str());
	}

}
void let_var(vector<string> v){
	string w = v[v.size()-1];
	if(var_globais.count(w)!=0){
		string msg = "Erro: a variável '"+w+"' já foi declarada na linha "+to_string(var_globais[w])+halt;
		yyerror(msg.c_str());
	}
	else{
		var_globais[w]=linha;
	}
}



void New_Inst( string st ) {
	codigo.push_back(st);
}


void New_Inst( vector<string> &st ){
	New_Inst(st[st.size()-1]);
}


void New_FInst( string st ) {
	func_codigo.push_back(st);
}


void New_FInst( vector<string> &st ){
	New_FInst(st[st.size()-1]);
}

int get_id(){
	static int id;
	return id++;
}
int get_func_id(){
	static int id;
	return id++;
}

string gera_ini_label(string pref,int id){
	return pref+to_string(id)+":";
}
string gera_fim_label(string pref, int id){
	return ":"+pref+to_string(id)+":";

}

vector<string> resolve_enderecos( vector<string> &entrada ) {
  map<string,int> label;
  vector<string> saida;
  int cont=0;

  for( unsigned int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = cont;
    else{
      if(entrada[i]!="\n")cont++;
      saida.push_back( entrada[i] );
  	}
  for( unsigned int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

int main() {
	yyparse();
	//imprime_codigo(codigo); cout<<"\n\n";
	New_Inst(halt);
	New_Line();
	codigo = codigo + func_codigo;
	codigo = resolve_enderecos(codigo);
	imprime_codigo(codigo);
	//cout<<endl<<endl;
	
	
	return 0;
}
