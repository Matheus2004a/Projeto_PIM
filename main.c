#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "obras/obras.h"
#include "menu/menu.h"
#include "usuarios/usuarios.h"

#define MAX_OBRAS 100

typedef struct
{
  char titulo[100];
  char descricao[400];
  char autor[50];
  int ano;
} Obra;

Obra obras[MAX_OBRAS];
int numObras = 0;

void cadastrarObra()
{
  if (numObras < MAX_OBRAS)
  {
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

    numObras++;
  }
  else
  {
    printf("Limite de obras atingido!\n");
  }
}

int questionario()
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

int main()
{
  setlocale(LC_ALL, "PORTUGUESE");

  int opcao;
  int usuarioLogado = -1;

  do
  {
    opcao = menu();

    switch (opcao)
    {
    case 1:
      cadastrarUsuario();
      break;
    case 2:
      usuarioLogado = fazerLogin();

      if (usuarioLogado != -1)
      {
        printf("Login bem-sucedido!\n");
      }
      else
      {
        printf("Usuario ou senha incorretos!\n");
      }
      break;
    case 3:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
    }
  } while (opcao != 3);

  return 0;
}
