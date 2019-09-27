%{ // Código em C/C++

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _COMENTARIO };

%}

/* Coloque aqui definições regulares */
D	[0-9]
L	[A-Za-z_]

WS	[ \t\n]
FOR	([Ff][Oo][Rr])
IF	([Ii][Ff])
ID	({L}|"$")({L}|{D}|"$")*
INT	{D}+
FLOAT	{INT}("."{INT})?([Ee]("+"|"-")?{INT})?
MAIG	">="
MEIG	"<="
IG	"=="
DIF "!="
COMENTARIO	([\/][\/][^\n]*)|(([\/][\*](([\*][^\/])|([\/][^\/])|[^\/])*[\*][\/]))
STRING ([\"]([^\"\n]*(\"\")*(\\\")*)*[\"])

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	{ /* ignora espaços, tabs e '\n' */ }
{FOR}	{ return _FOR;}
{IF}	{ return _IF;}
{COMENTARIO}	{ return _COMENTARIO;}
{STRING} 	{ return _STRING;} 
{INT}	{ return _INT;}
{FLOAT}	{ return _FLOAT;}
{MAIG}	{ return _MAIG;}
{MEIG}	{ return _MEIG;}
{IG}	{ return _IG;}
{DIF}	{ return _DIF;}
{ID}	{ return _ID;}
.       { return *yytext; 
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%
/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */

#include <stdio.h>
#include <string>

using namespace std;

extern "C" int yylex();  
extern "C" FILE *yyin;

void yyerror(const char* s);  

#include "lex.yy.c"

auto p = &yyunput;

int main() {
  int token = 0;
  
  while( (token = yylex()) != 0 )  
    printf( "%d %s\n", token, yytext );
  
  return 0;
}
