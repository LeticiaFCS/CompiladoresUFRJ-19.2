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

void erro( string msg );
void New_Inst( string st ); //nova instrução
void New_Inst( vector<string> &st );
void Pula_linha();
void imprime_codigo();
void get_var(vector<string> v);
void let_var(vector<string> v);
string gera_ini_label(string pref,int id);
string gera_fim_label(string pref,int id);
int get_id();
// protótipo para o analisador léxico (gerado pelo lex)
int yylex();
void yyerror( const char* );
int retorna( int tk );

int linha = 1;
int coluna = 1;


vector<string> codigo;
map<string,int> var_globais;

%}

%token NUM NEGNUM STR ID PRINT LET NEWOBJ NEWARRAY IF ELSE IGUAL

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
           {New_Inst(gera_ini_label("INI_IF",$1.id));New_Inst("?");
           Pula_linha();
           New_Inst(gera_ini_label("ELSE_IF",$1.id));New_Inst("#");
           Pula_linha();
           New_Inst(gera_fim_label("INI_IF",$1.id));}
           BLOCO 
           {New_Inst(gera_ini_label("FIM_IF",$1.id));New_Inst("#");}
           ELSE_LINHA 
           {New_Inst(gera_fim_label("ELSE_IF",$1.id));}
           BLOCO{New_Inst(gera_fim_label("FIM_IF",$1.id));} 
         ;

ELSE_LINHA:
		  |ELSE
		  ;

Decl : ID { New_Inst( $1.v ); let_var($1.v); New_Inst("&"); Pula_linha();} ',' Decl
	 | ID { New_Inst( $1.v ); let_var($1.v); New_Inst("&"); Pula_linha();} ';' 
	 | Adecl ',' Decl
	 | Adecl ';'
	 ;
	 
Adecl : ID { New_Inst( $1.v ); let_var($1.v); New_Inst("&"); New_Inst( $1.v ); }'=' RVALUE { New_Inst( "=" ); New_Inst( "^" ); Pula_linha(); }
	  ;

P : A ';' P
	| A ';'
	;

A : ID { New_Inst( $1.v ); get_var($1.v);} '=' RVALUE { New_Inst( "=" ); New_Inst( "^" ); Pula_linha(); }
  | LVALUEPROP '=' RVALUE { New_Inst( "[=]" ); New_Inst( "^" ); Pula_linha(); }
  | PRINT RVALUE { New_Inst( "print" ); New_Inst( "#" ); Pula_linha(); }
  ;

LVALUEPROP : E '.' LVALUEPROPSUFFIX
		   | E'['E']''.'{New_Inst("[@]");}LVALUEPROPSUFFIX
		   | E'['E']'
		   ;
LVALUEPROPSUFFIX: ID { New_Inst( $1.v );}
				| ID { New_Inst( $1.v );}{New_Inst("[@]");}'['ELPROP']'
				| ID { New_Inst( $1.v );}'.'{New_Inst("[@]");}LVALUEPROPSUFFIX
				| ID { New_Inst( $1.v );}'.'{New_Inst("[@]");}LVALUEPROPSUFFIX'['ELPROP']'
				;
				

RVALUE : E
	   | NEWOBJ {New_Inst("{}");}
	   | NEWARRAY {New_Inst("[]");}
	   | A { New_Inst( $1.v ); get_var($1.v); New_Inst("@");}
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
		| ID '(' PARAM ')' { New_Inst( $1.v ); New_Inst("#") ;}
		;
	
	
F : ID { New_Inst( $1.v ); get_var($1.v); New_Inst("@"); }
	| NUM { New_Inst(	$1.v ); }
	| NEGNUM {int sz=$1.v.size()-1; $1.v[sz]=$1.v[sz].substr(1);New_Inst("0"); New_Inst($1.v[sz] ); New_Inst("-");}
	| STR { New_Inst(	$1.v ); }
	| '(' RVALUE ')'
	| ID '(' PARAM ')' { New_Inst( $1.v ); New_Inst("#"); }
	| LVALUEPROP {New_Inst("[@]");}
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
	{ PRINT, "print" },
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



void Pula_linha(){
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
		string msg = "Erro: a variável '"+w+"' já foi declarada na linha "+to_string(var_globais[w])+".";
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

int get_id(){
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
