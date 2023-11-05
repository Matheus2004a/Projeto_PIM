#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "obras/obras.h"
#include "menu/menu.h"
#include "usuarios/usuarios.h"

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
        questionario();
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
