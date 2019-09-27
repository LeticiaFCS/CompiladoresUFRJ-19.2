#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum TOKEN { NUM = 256, ID };

string lexema;
vector<string> pilha;
map<string, double> var;

void push( double valor ) {
  pilha.push_back( to_string( valor ) );
}
void push( string valor ) {
  pilha.push_back( valor );
}

string pop_string() {
  string temp = pilha.back();
  pilha.pop_back();
  return temp;
}

double pop_double() {
  double temp = stod( pilha.back() );
  pilha.pop_back();
  return temp;
}

int next_token() {
  static int look_ahead = ' ';
  
  while( look_ahead == ' ' || look_ahead == '\n' )
     look_ahead = getchar();
  
  if( isdigit( look_ahead ) ) {
    lexema = (char) look_ahead;
    
    look_ahead = getchar();
    return NUM;
  }
  
  if( isalpha( look_ahead ) ) {
    lexema = (char) look_ahead;
    
    look_ahead = getchar();
    return ID;
  }

  switch( look_ahead ) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case '@':
      int temp = look_ahead;
      look_ahead = getchar();
      return temp;
  }
  
  return EOF;
}

int main() {
  int token = next_token();
  
  while( token != EOF ) {
    double op1, op2;
    
    switch( token ) {
      case NUM:
	push( lexema ); 
	break;

      case ID:
	push( lexema );
	break;
	
      case '@':
	push( var[pop_string()] );
	break;
	
      case '=':
	op2 = pop_double();
	var[pop_string()] = op2;
	break;
	
      case '+':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 + op2 ); 
	break;

      case '-':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 - op2 ); 
	break;

      case '/':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 / op2 ); 
	break;

      case '*':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 * op2 ); 
	break;
    }
    
    token = next_token();
  }
  
  for( string x : pilha )
    cout << x << " ";
  
  cout << endl;
}
