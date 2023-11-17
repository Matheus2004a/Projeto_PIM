#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "obras/obras.h"
#include "menu/menu.h"
#include "usuarios/usuarios.h"
#include "questionarios/visitantes/questionario_obra.h"
#include "vendaingresso/vendaing.h"
#include "menuVisitante/visitantes.h"

int main()
{
  setlocale(LC_ALL, "PORTUGUESE");

  int opcao;
  int usuarioLogado = -1;

  preCadastrarObra("Pele", "Rei do futebol", "Edson Pele", 2000);
  preCadastrarObra("Santos", "Time grande", "Robinho", 2010);
  preCadastrarObra("SPFC", "Time gigante", "Cauã", 2020);

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
