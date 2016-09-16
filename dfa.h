#ifndef __DFA_H
#define __DFA_H

#define bool short
#define true 1
#define false 0

#define MAX_ELEMENT 1000
#define MAX_SYMBOL 256
#define MAX_LENGTH 1000

extern char * idElement[MAX_ELEMENT];
extern char idSymbol[MAX_SYMBOL];
extern int toWhere[MAX_ELEMENT][MAX_SYMBOL];
extern bool isFinal[MAX_ELEMENT];

extern int nElement, nSymbol, nFinal;
extern int startState;

void initDFA();

void setIdElement(int number, char * str);

void setIdSymbol(int number, char c);

int getIdElement(char * str);

int getIdSymbol(char c);

int next(int now, char c);

#endif
