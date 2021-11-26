// Write a recursive descent parser for the following simple grammars.

/*
Grammar:
S -> (L) | a
L -> L,S | S

The production rule for L is left recursive. This needs to be eliminated
L -> SL'
L' -> ,SL' | ε

Therefore, the grammar is:
S -> (L) | a
L -> SL'
L' -> ,SL' | ε
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int curr = 0;
char str[512];

void S();
void L();
void L_();

void invalid()
{
	printf("Invalid String\n");
	exit(-1);
}

void valid()
{
	printf("Valid String\n");
	exit(0);
}

void S()
{
	if (str[curr] == '(') {
		curr++;
		L();
		if (str[curr] == ')') {
			curr++;
			return;
		}
		else {
			invalid();
		}
	}
	else if (str[curr] == 'a') {
		curr++;
		return;
	}
	else {
		invalid();
	}
}

void L()
{
	S();
	L_();
} 

void L_()
{
	if (str[curr] == ',') {
		curr++;
		S();
		L_();
	}
	return;
}

int main()
{
	printf("Enter a string (Mark end of string with $):\n");
	scanf("%s", str);
	S();
	if (str[curr] == '$') {
		valid();
	}
	else {
		invalid();
	}
	return 0;
}