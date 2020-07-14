DIGITO  [0-9]
LETRA   [A-Za-z_]
DOUBLE  {DIGITO}+("."{DIGITO}+)?
NEGDOUBLE ("-"{DOUBLE})
ID      {LETRA}({LETRA}|{DIGITO})*
STR 	(\"([^\"\n]|(\\\")|\"\")+\")|(\'([^\'\n]|(\\\')|\'\')+\')

%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	   { linha++; coluna = 1; }

{DOUBLE}   { return retorna( NUM ); }
{NEGDOUBLE}   { return retorna( NEGNUM ); }

{STR}	   { return retorna( STR ); }

"let"	   { return retorna( LET );}
"if"       { return retorna( IF );}
"{}"	   { return retorna( NEWOBJ );}
"[]"	   { return retorna( NEWARRAY );} 


{ID}       { return retorna( ID ); }

.          { return retorna( *yytext ); }

%% 
