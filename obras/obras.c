#include <stdio.h>
#include <stdlib.h>

int administraObras()
{
  int selecao;

  printf("1 - Criar uma obra \n");
  printf("2 - Selecione uma obra para editá - la \n");
  printf("3 - Exclua uma obra \n");
  printf("4 - Voltar tela inicial ");
  scanf("%d", &selecao);

  switch (selecao)
  {
  case 1:
    cadastrarObra();
    break;
  case 2:
    printf("Alterar obra existente");
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
}
