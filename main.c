#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

#define MAX_ELEMENT 1000
#define MAX_SYMBOL 256
#define MAX_LENGTH 1000

char * idElement[MAX_ELEMENT];
char idSymbol[MAX_SYMBOL];
int toWhere[MAX_ELEMENT][MAX_SYMBOL];

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


void init(){
  int i;

  for(i=0;i<MAX_ELEMENT;i++){
    idElement[i] = NULL;
  }

  memset(idSymbol, 0, sizeof(idSymbol));
  memset(toWhere, -1, sizeof(toWhere));
}

void readFile(char * filename){
  FILE *f;
  int n,i;
  char *inp = malloc(MAX_LENGTH+5);

  f = fopen(filename, "r");

  fscanf(f, "%d", &n);
  assert(n <= MAX_ELEMENT);

  for(i=0;i<n;i++){
    fscanf(f,"%s", inp);
    setIdElement(0,inp);
  }

  fscanf(f, "%s", inp);
  assert(strlen(inp)<=MAX_SYMBOL);
}

int main(){
  init();
  return 0;
}
