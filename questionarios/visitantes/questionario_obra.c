#include <stdio.h>
#include <stdlib.h>

int questionario_obra()
{
  char nome[50], time[20];
  int idade;

  printf("Digite seu nome:");
  scanf("%s", &nome);

  printf("\n Digite sua idade: ");
  scanf("%d", &idade);

  printf("\n Qual o time voce torce?");
  scanf("%s", &time);
}
