#include <stdio.h>

#include "listagem/listar_obras.h"
#include "cadastro/cadastrar_obra.h"
#include "edicao/editar_obra.h"
#include "remocao/remover_obra.h"

int administraObras()
{
  int selecao, id;

  do
  {
    printf("1 - Criar uma obra \n");
    printf("2 - Editar uma obra \n");
    printf("3 - Exclua uma obra \n");
    printf("4 - Listar as obras \n");
    printf("5 - Voltar tela inicial \n");

    printf("Escolha uma opção: ");
    scanf("%d", &selecao);

    switch (selecao)
    {
    case 1:
      cadastrarObra();
      break;
    case 2:
      printf("Digite o ID da obra que deseja editar: ");
      scanf("%d", &id);
      editarObra(id);
      break;
    case 3:
      printf("Digite o ID da obra que deseja remover: ");
      scanf("%d", &id);
      removerObra(id);
      break;
    case 4:
      listarObras();
      break;
    case 5:
      printf("Saindo...");
      break;
    default:
      printf("Opção inválida!");
      break;
    }
  } while (selecao != 5);
}
