DIGITO  [0-9]
LETRA   [A-Za-z_]
DOUBLE  {DIGITO}+("."{DIGITO}+)?
NEGDOUBLE ("-"{DOUBLE})
ID      {LETRA}({LETRA}|{DIGITO})*
STR 	(\"([^\"\n]|(\\\")|\"\")+\")|('([^'\n]|(\\')|'')+')

%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	   { linha++; coluna = 1; }

{DOUBLE}   { return retorna( NUM ); }
{NEGDOUBLE}   { return retorna( NEGNUM ); }

{STR}	   { return retorna( STR ); }

"let"	   { return retorna( LET );}
"if"       { return retorna( IF );}
"else"     { return retorna( ELSE );}
"return"   { return retorna( RETURN );} 
"function" { return retorna( FUNCTION);}
"{}"	   { return retorna( NEWOBJ );}
"[]"	   { return retorna( NEWARRAY );}
"=="       { return retorna( IGUAL );} 
">="       { return retorna( MAI_IG );} 
"<="       { return retorna( MEN_IG );} 
"asm{".*"}" {string lexema = trim(yytext+3,'{','}');
			 yylval.v= tokeniza( lexema );
			 yylval.v.push_back(pop);
			 coluna += strlen( yytext);
			 return ASM;
			}

{ID}       { return retorna( ID ); }

.          { return retorna( *yytext ); }

%% 
