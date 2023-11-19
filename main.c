#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "obras/obras.h"
#include "obras/cadastro/pre_cadastro.h"
#include "menu/menu.h"
#include "usuarios/login.h"
#include "usuarios/cadastro.h"

int main()
{
  setlocale(LC_ALL, "PORTUGUESE");

  int opcao;
  int usuarioLogado = -1;

  preSaveObra();

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

      if (usuarioLogado == -1)
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
