#include "dfa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char * idElement[MAX_ELEMENT];
char idSymbol[MAX_SYMBOL];
int toWhere[MAX_ELEMENT][MAX_SYMBOL];
bool isFinal[MAX_ELEMENT];

int nElement, nSymbol, nFinal;
int startState;

void setIdElement(int number, char * str){
  idElement[number] = malloc(strlen(str)+1);
  strcpy(idElement[number],str);
}

void setIdSymbol(int number, char c){
  idSymbol[number] = c;
}

int getIdElement(char * str){
  int i=0;
  bool found = false;

  while(true){
    if (i==MAX_ELEMENT) break;
    if (idElement[i]==NULL) break;
    if (strcmp(idElement[i],str)==0){
      found = true;
      break;
    }

    i++;
  }

  assert(found);
  return i;
}

int getIdSymbol(char c){
  int i=0;
  bool found = false;

  while(true){
    if (i==MAX_SYMBOL) break;
    if (idSymbol[i]==0) break;
    if (idSymbol[i]==c){
      found = true;
      break;
    }

    i++;
  }

  assert(found);
  return i;
}

int next(int now, char c){
  int ret = toWhere[now][getIdSymbol(c)];
  assert(ret!=-1);

  return ret;
}
