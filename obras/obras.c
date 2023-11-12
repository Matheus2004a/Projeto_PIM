#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OBRAS 100

typedef struct
{
  int id;
  char titulo[100];
  char descricao[400];
  char autor[50];
  int ano;
} Obra;

Obra obras[MAX_OBRAS];
int numObras = 0;

int gerarIdAleatorio()
{
  srand((unsigned int)time(NULL));
  return rand();
}

void listarObras()
{
  printf("Lista de Obras Disponíveis:\n");

  for (int i = 0; i < numObras; i++)
  {
    printf("ID: %d \n", obras[i].id);
    printf("Título: %s", obras[i].titulo);
    printf("Descrição: %s", obras[i].descricao);
    printf("Autor: %s", obras[i].autor);
    printf("Ano: %d \n", obras[i].ano);
  }
}

void cadastrarObra()
{
  if (numObras < MAX_OBRAS)
  {
    obras[numObras].id = gerarIdAleatorio();

    printf("Digite o título da obra: ");
    getchar(); // Limpar o buffer de entrada
    fgets(obras[numObras].titulo, sizeof(obras[numObras].titulo), stdin);

    printf("Digite o descrição da obra: ");
    getchar();
    fgets(obras[numObras].descricao, sizeof(obras[numObras].descricao), stdin);

    printf("Digite o autor da obra: ");
    fgets(obras[numObras].autor, sizeof(obras[numObras].autor), stdin);

    printf("Digite o ano da obra: ");
    scanf("%d", &obras[numObras].ano);

    system("cls");

    printf("\n Obra cadastrada com sucesso! \n");
    numObras++;
  }
  else
  {
    printf("Limite de obras atingido!\n");
  }
}

int administraObras()
{
  int selecao;

  do
  {
    printf("1 - Criar uma obra \n");
    printf("2 - Editar uma obra \n");
    printf("3 - Exclua uma obra \n");
    printf("4 - Voltar tela inicial \n");

    printf("Escolha uma opção: ");
    scanf("%d", &selecao);

    switch (selecao)
    {
    case 1:
      cadastrarObra();
      break;
    case 2:
      printf("Editar obra existente");
      break;
    case 3:
      printf("Excluir obra existente");
      break;
    case 4:
      printf("Saindo...");
      break;
    default:
      printf("Opção inválida!");
      break;
    }
  } while (selecao != 4);
}
