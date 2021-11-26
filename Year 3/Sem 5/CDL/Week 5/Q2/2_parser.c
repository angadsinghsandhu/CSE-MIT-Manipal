
// Write a recursive descent parser for the following simple grammars.

/* Grammar:
S -> UVW
U -> (S) | aSb | d
V -> aV | ε
W -> cW | ε

There is no left recurison in this grammar
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int curr = 0;
char str[512];

void S();
void U();
void V();
void W();

void invalid() {
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
	U();
	V();
	W();
}

void U()
{
	if (str[curr] == '(')
	{
		curr++;
		S();
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
		S();
		if (str[curr] == 'b') {
			curr++;
			return;
		}
		else {
			invalid();
		}
	}
	else if (str[curr] == 'd') {
		curr++;
		return;
	}
}

void V()
{	if (str[curr] == 'a') {
		curr++;
		V();
	}
	return;
}

void W()
{
	if (str[curr] == 'c') {
		curr++;
		W();
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
