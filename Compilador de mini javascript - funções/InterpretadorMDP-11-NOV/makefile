all: interpretador
	./interpretador -debug < entrada.fi

clean:
	rm -f lex.yy.mdp.c interpretador *.o
	
interpretador: lex.yy.mdp.o var_object.cc mdp.h mdp.cc
	 g++ -Wall -std=c++17 lex.yy.mdp.o mdp.cc -ll -o interpretador 
		
lex.yy.mdp.o: lex.yy.mdp.c 
	g++ -Wall -std=c++14 -c lex.yy.mdp.c 
	
lex.yy.mdp.c: mdp.l 
	lex -o lex.yy.mdp.c mdp.l 
