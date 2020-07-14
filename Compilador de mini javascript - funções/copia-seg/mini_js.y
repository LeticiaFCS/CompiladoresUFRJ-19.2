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

%}

%token NUM NEGNUM STR ID LET NEWOBJ NEWARRAY IF ELSE IGUAL MAI_IG MEN_IG

%left '.'
%left '+' '-'
%left '*' '/'

%right '='


%%


START : CMD
      ;

CMD : LET Decl CMD
	| P CMD
	| IF_LINHA CMD
	| ID '(' PARAM ')' { 
	   New_Inst( $1.v ); 
	   New_Inst(let); 
	   New_Inst( $1.v );
	   New_Inst("{}");
	   New_Inst(set);
	   New_Inst("'&funcao'");
	   New_Inst(gera_ini_label("FUNC",get_func_id()));
	   New_Inst(setProp);
	   New_Inst(pop);
	  } '{' CMD '}'';' {New_Line();}CMD
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
  | ID RVALUE { New_Inst( "print" ); New_Inst( jump ); New_Line(); }
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
	   | ID '('PARAM')' {New_Inst($1.v); New_Inst(get); New_Inst(callFunc);}
	   ;
E : E '+' E { New_Inst( "+" ); }
	| E '-' E { New_Inst( "-" ); }
	| E '*' E { New_Inst( "*" ); }
	| E '/' E { New_Inst( "/" ); }
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
	  | FLPROP
	  ;

FLPROP: ID { New_Inst( $1.v ); }
		| NUM { New_Inst(	$1.v ); }
		| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_Inst("0"); New_Inst($1.v[sz] ); New_Inst("-");}
		| STR { New_Inst(	$1.v ); }
		| '(' RVALUE ')'
		| ID '(' PARAM ')' { New_Inst( $1.v ); New_Inst(jump) ;}
		;
	
	
F : ID { New_Inst( $1.v ); get_var($1.v); New_Inst(get); }
	| NUM { New_Inst(	$1.v ); }
	| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_Inst("0"); New_Inst($1.v[sz] ); New_Inst("-");}
	| STR { New_Inst(	$1.v ); }
	| '(' RVALUE ')'
	| LVALUEPROP {New_Inst(getProp);}
	;
	
PARAM : ARGs
	  |
	  ;
	
ARGs : RVALUE ',' ARGs
	 | RVALUE
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

void imprime_codigo(vector<string> &codigo){
	int cont=0;
	for(int i=0;i<codigo.size();i++){
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
	New_Inst(st[st.size()-1]);
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

  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = cont;
    else{
      if(entrada[i]!="\n")cont++;
      saida.push_back( entrada[i] );
  	}
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

int main() {
	yyparse();
	//imprime_codigo(codigo); cout<<"\n\n";
	codigo = resolve_enderecos(codigo);
	imprime_codigo(codigo);
	cout<<".\n";
	return 0;
}
