
// Write a recursive descent parser for the following simple grammars.

/*
Grammmar:
S -> aAcBe
A -> Ab|b
B -> d

The production rule for A has left recursion which needs to be eliminated
A -> bA'
A' -> bA' | ε

Therefore, the rules are:
S -> aAcBe
A -> bA'
A' -> bA' | ε
B -> d
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int curr = 0;
char str[512];

void S();
void A();
void A_();
void B();

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
		curr++;
		A();
		if (str[curr] == 'c') {
			curr++;
			B(); if (str[curr] == 'e') {
				curr++;
				return;
			}
			else {
				invalid();
			}
		}
		else {
			invalid();
		}
	}
	else {
		invalid();
	}
}

void A()
{
	if (str[curr] == 'b') {
		curr++;
		A_();
		return;
	}
	else {
		invalid();
	}
}

void A_()
{
	if (str[curr] == 'b') {
		curr++;
		A_();
	}
	return;
}

void B()
{
	if (str[curr] == 'd') {
		curr++;
		return;
	}
	else {
		invalid();
	}
}


int main()
{
	printf("Enter a string (Mark end of string with $):\n"); scanf("%s", str);
	S();
	if (str[curr] == '$') {
		valid();
	}
	else {
		invalid();
	}
	return 0;
}