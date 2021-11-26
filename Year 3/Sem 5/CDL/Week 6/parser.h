#ifndef PARSER_H__
#define PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include "la.h"
#include "utils/parser/parserutils.h"

FILE *f;
token_t *tkn;
int ret = 0;

// Create a function for every non terminal in the grammar
// PROGRAM is our start symbol
void PROGRAM();
void DECLARATIONS();
void DATA_TYPE();
void IDENTIFIER_LIST();
void IDENTIFIER_LIST_();
void ASSIGN_STAT();
void ASSIGN_STAT_();

int parse(FILE *fb)
{
    f = fb;
    tkn = (token_t *)malloc(sizeof(token_t));

    // Get the first token and start parsing!
    // Program is our start symbol
    ret = getNextToken_(f, tkn);
    PROGRAM();

    // By the end of parsing, ret should be TKN_EOF
    // i.e., we should have reached end of file
    // If we are here, then the code is valid, else,
    // it is invalid
    if (ret == TKN_EOF) {
        ret = 0;
        valid();
    }
    else
    {
        invalid(-1, -1, "Expected End of File", tkn->lexName);
    }
    return ret;
}

void PROGRAM()
{
    if (strcmp(tkn->lexName, "int") == 0) {
        ret = getNextToken_(f, tkn);
        if (strcmp(tkn->lexName, "main") == 0) {
            ret = getNextToken_(f, tkn);
            if (strcmp(tkn->lexName, "(") == 0) {
                ret = getNextToken_(f, tkn);
                if (strcmp(tkn->lexName, ")") == 0) {
                    ret = getNextToken_(f, tkn);
                    if (strcmp(tkn->lexName, "{") == 0) {
                        ret = getNextToken_(f, tkn);
                        DECLARATIONS();
                        ASSIGN_STAT();
                        ret = getNextToken_(f, tkn);
                        if (strcmp(tkn->lexName, "}") == 0) {
                            ret = getNextToken_(f, tkn);
                            return;
                        } else {
                            invalid(tkn->row, tkn->col, "PROGRAM. Expected }", tkn->lexName);
                        }
                    } else {
                        invalid(tkn->row, tkn->col, "PROGRAM. Expected {", tkn->lexName);
                    }
                } else {
                    invalid(tkn->row, tkn->col, "PROGRAM. Expected )", tkn->lexName);
                }
            } else {
                invalid(tkn->row, tkn->col, "PROGRAM. Expected (", tkn->lexName);
            }
        } else {
            invalid(tkn->row, tkn->col, "PROGRAM. Expected main", tkn->lexName);
        }
    } else {
        invalid(tkn->row, tkn->col, "PROGRAM. Expected int", tkn->lexName);
    }
}

void DECLARATIONS()
{
    if (strcmp(tkn->lexName, "int") == 0 || strcmp(tkn->lexName, "char") == 0) {
        DATA_TYPE();
        ret = getNextToken_(f, tkn);
        IDENTIFIER_LIST();
        if (strcmp(tkn->lexName, ";") == 0) {
            ret = getNextToken_(f, tkn);
            DECLARATIONS();
        } else {
            invalid(tkn->row, tkn->col, "DECLARATIONS. Expected ;", tkn->lexName);
        }
    }
    else if (strcmp(tkn->type, "ID") == 0) {
        return;
    }
    else {
        invalid(tkn->row, tkn->col, "DECLARATIONS. Expected declaration statments", tkn->lexName);
    }
}

void DATA_TYPE()
{
    if (strcmp(tkn->lexName, "int") == 0) {
        return;
    }
    else if (strcmp(tkn->lexName, "char") == 0) {
        return;
    }
    else {
        invalid(tkn->row, tkn->col, "DATA_TYPE. Expected data type (int/char)", tkn->lexName);
    }
}

void IDENTIFIER_LIST()
{
    if (strcmp(tkn->type, "ID") == 0) {
        ret = getNextToken_(f, tkn);
        IDENTIFIER_LIST_();
        return;
    }
    else {
        invalid(tkn->row, tkn->col, "IDENTIFIER_LIST. Expected identifier", tkn->lexName);
    }
}

void IDENTIFIER_LIST_()
{
    if (strcmp(tkn->lexName, ";") == 0) {
        return;
    }
    else if (strcmp(tkn->lexName, ",") == 0) {
        ret = getNextToken_(f, tkn);
        IDENTIFIER_LIST();
    }
    else {
        invalid(tkn->row, tkn->col, "IDENTIFIER_LIST_.Expected ; or ,", tkn->lexName);
    }
}

void ASSIGN_STAT()
{
    if (strcmp(tkn->type, "ID") == 0) {
        ret = getNextToken_(f, tkn);
        if (strcmp(tkn->lexName, "=") == 0) {
            ret = getNextToken_(f, tkn);
            ASSIGN_STAT_();
        } else {
            invalid(tkn->row, tkn->col, "ASSIGN_STAT. Expected =", tkn->lexName);
        }
    }
    else if (strcmp(tkn->lexName, "}") == 0) {
        return;
    } 
    else {
        invalid(tkn->row, tkn->col, "ASSIGN_STAT. Expected identifier", tkn->lexName);
    }
}

void ASSIGN_STAT_()
{
    if (strcmp(tkn->type, "ID") == 0) {
        ret = getNextToken_(f, tkn);
        if (strcmp(tkn->lexName, ";") == 0) {
            ret = getNextToken_(f, tkn);
            ASSIGN_STAT();
        } else {
            invalid(tkn->row, tkn->col, "ASSIGN_STAT_. Expected ; after assignment", tkn->lexName);
        }
    }
    else if (strcmp(tkn->type, "NUM") == 0) {
        ret = getNextToken_(f, tkn);
        if (strcmp(tkn->lexName, ";") == 0) {
            ret = getNextToken_(f, tkn);
            ASSIGN_STAT();
        } else {
            invalid(tkn->row, tkn->col, "ASSIGN_STAT_. Expected ; after assignment", tkn->lexName);
        }
    }
    else {
        invalid(tkn->row, tkn->col, "ASSIGN_STAT_. Expected identifier or number", tkn->lexName);
    }
}

#endif