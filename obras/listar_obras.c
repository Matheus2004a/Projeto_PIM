#include <stdio.h>

#include "dados_obra.h"

void listarObras()
{
  printf("Lista de Obras Disponíveis:\n");

  if (numObras <= 0)
  {
    printf("Nenhuma obra cadastrada \n");
    return;
  }

  for (int i = 0; i < numObras; i++)
  {
    printf("ID: %d \n", obras[i].id);
    printf("Título: %s \n", obras[i].titulo);
    printf("Descrição: %s \n", obras[i].descricao);
    printf("Autor: %s \n", obras[i].autor);
    printf("Ano: %d \n", obras[i].ano);
  }
}
