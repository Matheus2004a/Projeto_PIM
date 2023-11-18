#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "obras/obras.h"
#include "menu/menu.h"
#include "usuarios/login.h"
#include "usuarios/cadastro.h"
#include "questionarios/visitantes/questionario_obra.h"
#include "vendaingresso/vendaing.h"
#include "menuVisitante/visitantes.h"

int main()
{
  setlocale(LC_ALL, "PORTUGUESE");

  int opcao;
  int usuarioLogado = -1;

  preCadastrarObra(
      "Pele, o rei do futebol",
      "Edson Arantes do Nascimento, mais conhecido como Pelé, foi um futebolista brasileiro que atuou como atacante/Rei do Futebol.",
      "Edson Pele",
      2000);
  preCadastrarObra(
      "Santos FC",
      "O Santos Futebol Clube, mais conhecido como Santos, é um clube poliesportivo brasileiro",
      "Celso Unzelte",
      2012);
  preCadastrarObra(
      "SPFC",
      "O São Paulo Futebol Clube, é um clube poliesportivo brasileiro da cidade de São Paulo",
      "Cauã",
      2023);

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
