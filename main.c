#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "dfa.h"

#define LANG_MAX_LENGTH 1001

void readFile(char * filename);

int main(int argc, char ** argv){
  int i;
  int now;
  int len;

  char str[LANG_MAX_LENGTH];

  initDFA();
  if (argc>1) readFile(argv[1]);
  else readFile("deskripsi.dat");

  printf("Tulis string input, maksimal %d karakter :\n", LANG_MAX_LENGTH-1);
  fgets(str, LANG_MAX_LENGTH, stdin);
  len = strlen(str);

  now = startState;

  printf("->%s\n", idElement[startState]);

  for(i = 0; i < len-1; i++){
    now = toWhere[now][getIdSymbol(str[i])];
    printf("Mendapat input '%c', sekarang ada di state %s\n", str[i], idElement[now]);
  }

  if (isFinal[now]){
    printf("Berakhir di Final State, yaitu %s. String diterima\n", idElement[now]);
  }
  else{
    printf("Berakhir tidak di Final State, yaitu %s. String ditolak\n", idElement[now]);
  }
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

    setIdElement(i,inp);
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
