
// Write a recursive descent parser for the following simple grammars.

/* 
Grammar:
S -> a | > | (T)
T -> T,S|S

We need to eliminate left recursion in the production of T
T -> ST'
T' -> ,ST' | ε

Therefore, the grammar is:
S -> a | > | (T)
T -> ST'
T' -> ,ST' | ε
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr = 0;
char str[512];
void S();
void T();
void T_();

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
	if (str[curr] == 'a') {
		curr++;return;
	} else if (str[curr] == '>') {
		curr++;
		return;
	} else if (str[curr] == '(') {
		curr++;
		T();

		if (str[curr] == ')') {
			curr++;
			return;
		} else {
			invalid();
		}
	}
}

void T()
{
	S();
	T_();
}

void T_()
{
	if (str[curr] == ',') {
	curr++;
	S();
	T_();
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
	} else {
		invalid();
	}

	return 0;
}