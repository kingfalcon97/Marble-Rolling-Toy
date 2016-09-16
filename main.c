#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define bool short
#define true 1
#define false 0

#define MAX_ELEMENT 1000
#define MAX_SYMBOL 256
#define MAX_LENGTH 1000

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


void init(){
  int i;

  for(i=0;i<MAX_ELEMENT;i++){
    idElement[i] = NULL;
  }

  memset(idSymbol, 0, sizeof(idSymbol));
  memset(toWhere, -1, sizeof(toWhere));
  memset(isFinal, 0, sizeof(isFinal));
}

void readFile(char * filename){
  FILE *f;
  int n,i,j;
  char *inp = malloc(MAX_LENGTH+5);

  f = fopen(filename, "r");

  assert(f!=NULL);

  /*(Jumlah state)*/
  fscanf(f, "%d", &n);
  assert(n <= MAX_ELEMENT);
  nElement = n;

  /*(Daftar state, dipisahkan spasi)*/
  for(i=0;i<nElement;i++){
    fscanf(f,"%s", inp);

    for(j=0;j<i;j++){
      assert(strcmp(inp,idElement[j])!=0);
    }

    setIdElement(0,inp);
  }

  /*(Daftar simbol, tidak dipisahkan spasi)*/
  fscanf(f, "%s", inp);
  assert(strlen(inp)<=MAX_SYMBOL);
  nSymbol = strlen(inp);

  for(i = 0; i < nSymbol; i++){
    for(j = 0; j < i; j++){
      assert(inp[i]!=inp[j]);
    }

    setIdSymbol(i, inp[i]);
  }

  /*(State awal)*/
  fscanf(f, "%s", inp);
  startState = getIdElement(inp);

  /*(Jumlah final state)*/
  fscanf(f, "%d", &n);
  assert(n <= nElement);
  nFinal = n;

  /*(Daftar state akhir, dipisahkan spasi)*/
  for(i=0;i<nFinal;i++){
    fscanf(f, "%s", inp);

    j = getIdElement(inp);
    assert(!(isFinal[j]));
    isFinal[j] = true;
  }

  /*(Transition function berbentuk tabel)*/
  for(i=0;i<nElement;i++){
    for(j=0;j<nSymbol;j++){
      fscanf(f,"%s",inp);
      toWhere[i][j] = getIdElement(inp);
    }
  }
}

int main(int argc, char ** argv){
  init();

  if (argc>1) readFile(argv[1]);
  else readFile("deskripsi.dat");
  return 0;
}
