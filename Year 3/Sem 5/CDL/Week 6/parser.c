/*
For  given  subset  of  grammar  7.1,  design  RD  parser  with  
appropriate error messages with expected character and row and column number.
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "la.h"

FILE *f;
struct token t;
void program();
void returntype();
void declarations();
int datatype();
void identifierlist(struct token);
void assign_stat(struct token);

void invalid(struct token *tkn){
	printf("error at row:%d, col:%d for lexeme \" %s \" \n",tkn->row,tkn->col,tkn->lexeme);
	printf("-----ERROR!-----\n");
	exit(1);
}

void valid(){
	printf("------SUCCESS!------\n");
	exit(0);
}

void program(){
    t = getNextToken(f);
    returntype();
    
    if(strcmp(t.lexeme,"main") == 0){
		t = getNextToken(f);
		if(strcmp(t.lexeme,"(") == 0){
			t = getNextToken(f);
			if(strcmp(t.lexeme,")") == 0){
				t = getNextToken(f);
				if(strcmp(t.lexeme,"{") == 0){
					declarations();
					t = getNextToken(f);
					if(strcmp(t.lexeme,"}") == 0) return;
					else invalid(&t);
				}
				else invalid(&t);
			}
			else invalid(&t);
		}
		else invalid(&t);
	}
	else invalid(&t);
}

void returntype(){
    t = getNextToken(f);
    if(strcmp(t.lexeme, "int")){
        return;
    }
    else{
        invalid(&t);
    }
}

void declarations(){
	t = getNextToken(f);
	if(datatype(t.lexeme)){
		t = getNextToken(f);
		identifierlist(t);
		t = getNextToken(f);
		
		if(strcmp(t.lexeme,";") == 0) 
			declarations();
		else invalid(&t);
	}
	else assign_stat(t);   // incase for the production declarations->E, it will be handled in assign_stat
}

int datatype(char *lx){
	if(strcmp(lx,"int")==0 || strcmp(lx,"char") == 0) return 1;
	else return 0;
}
void identifierlist(struct token t){
	struct token tkn;
	tkn = t;
	if(strcmp(tkn.type,"identifier") == 0){
		tkn = getNextToken(f);
		if(strcmp(tkn.lexeme,",") == 0){
			tkn = getNextToken(f);
			identifierlist(tkn);
		}
		else if(strcmp(tkn.lexeme,";") == 0){
			fseek(f,-1,SEEK_CUR);
			return;
		}
		else invalid(&tkn);
	}
}

void assign_stat(struct token t){
	struct token tkn;
	if(strcmp(t.type,"identifier") == 0){
		tkn = getNextToken(f);
		if(strcmp(tkn.lexeme,"=") == 0){
			tkn = getNextToken(f);
			if(strcmp(tkn.type,"number") == 0||strcmp(tkn.type,"identifier")){
				tkn = getNextToken(f);
				if(strcmp(tkn.lexeme,";") == 0) return;
				else invalid(&t);
			}
			else invalid(&t);
		}
		else invalid(&t);
	}
}

int main(){
    f = fopen("sample.c", "r");
    
    if(!f){
        printf("Error in opening file\n\n");
        printTable(tab, 10);
        exit(1);
    }

	program();
	valid();
}