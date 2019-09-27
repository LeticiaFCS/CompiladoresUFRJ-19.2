%{
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;
  
int token;

void A();
void E();
void E_linha();
void T();
void T_linha();
void F();
void casa( int );

enum { tk_int = 256, tk_char, tk_double, tk_id, tk_cte_int };
map<int,string> nome_tokens = {
  { tk_int, "int" },
  { tk_char, "char" },
  { tk_double, "double" },
  { tk_id, "nome de identificador" },
  { tk_cte_int, "constante inteira" }
};
%}

WS	[ \n\t]
DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+
ID	{LETRA}({LETRA}|{DIGITO})*

%%

{WS}  		{ }
{NUM} 		{ return tk_cte_int; }
"char"		{ return tk_char; }
"int"		{ return tk_int; }
"double"	{ return tk_double; }

{ID}		{ return tk_id; }

.		{ return yytext[0]; }

%%



int next_token() {
  return yylex();
}

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
}


void print( string msg ) {
  cout << msg << endl;
}

void erro(string msg){
	cout << "Erro: " << msg << endl;
	exit(1);
}

void A() {
// Guardamos o yytext pois a função 'casa' altera o seu valor.
  string temp = yytext; 
  casa( tk_id );
  print( temp );
  casa( '=' );
  E();
  print( "=" );
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); print( "+"); E_linha(); break;
    case '-' : casa( '-' ); T(); print( "-"); E_linha(); break;
  }
}

void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); F(); print( "*"); T_linha(); break;
    case '/' : casa( '/' ); F(); print( "/"); T_linha(); break;
  }
}

void F() {
  switch( token ) {
    case tk_id : {
      string temp = yytext;
      casa( tk_id ); print( temp + "@" ); } 
      break;
    case tk_cte_int : {
      string temp = yytext;
      casa( tk_cte_int ); print( temp ); }
      break;
    case '(': 
      casa( '(' ); E(); casa (')'); break;
    default:
      erro( "Operando esperado, encontrado " + string(yytext) );
  }
}

void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else {
    printf( "Esperado %d, encontrado: %d\n", esperado, token );
    exit( 1 );
  }
}

int main() {
  token = next_token();
  A();
  printf( "Sintaxe ok!\n" );
  
  return 0;
}
