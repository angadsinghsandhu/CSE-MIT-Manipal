/*
Design the recursive descent parser to parse array declarations and expression
statements with error reporting. Subset of grammar 7.1 is as follows:

Program -> main ( ) { Declarations Statement-List }
Declarations -> Data-Type Identifier-List ; Declarations | EP

Data-Type -> int | char

Identifier-List -> id Identifier-List-prime
Identifier-List-prime -> , Identifier-List | [ number ] Identifier-List-prime-prime | EP
Identifier-List-prime-prime -> , Identifier-List | EP

Statement-List -> Statement Statement-List | EP
Statement -> Assign-Stat ;
Assign-Stat -> id = Expn

Expn -> Simple-Expn Eprime
Eprime -> Relop Simple-Expn | EP
Simple-Expn -> Term SEprime 

SEprime -> Addop Term SEprime | EP
Term -> Factor Tprime
Tprime -> Mulop Factor Tprime | EP
Factor -> id | num

Relop -> == | != | <= | >= | > | <
Addop -> + | -
Mulop -> * | / | %
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "la.h"

FILE *f;
struct token t;

// functions
void program();
void declarations();
int datatype();

void identifierlist();
void identifierlist_();
void identifierlist__();

void statementlist();
void statement();
void assignStat();

void expn();
void e_();
void simpleExpn();

void se_();
void term();
void t_();
void factor();

void relop();
void addop();
void mulop();

// Valid, Invalid and returntype Functions
void invalid(struct token *tkn){
	printf("error at row:%d, col:%d, type:\"%s\" for lexeme \" %s \"\n",tkn->row,tkn->col, tkn->type, tkn->lexeme);
	printf("------ERROR!------\n");
	exit(1);
}

void valid(){
	printf("------SUCCESS!------\n");
	exit(0);
}

void returntype(){
    t = getNextToken(f);
    if(strcmp(t.lexeme, "int")==0 || strcmp(t.lexeme, "void")==0){
        return;
    }
    else{
        invalid(&t);
    }
}


// Helper Functions


// Driver Code
int main(){
	
}