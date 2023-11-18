#ifndef DADOS_OBRAS_H
#define DADOS_OBRAS_H

#define MAX_OBRAS 100

typedef struct
{
  int id;
  char titulo[100];
  char descricao[400];
  char autor[50];
  int ano;
} Obra;

extern Obra obras[MAX_OBRAS];
extern int numObras;

#endif
