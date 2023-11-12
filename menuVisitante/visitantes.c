#include <stdio.h>
#include <stdlib.h>

int escolherObras()
{
  int opcao;

  do
  {
    printf("Menu:\n");
    printf("1. Listar Obras Disponíveis\n");
    printf("2. Comprar ou Escolher Obra\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      listarObras();
      break;
    case 2:
      system("cls");
      fazerVendaIngresso();
      break;
    case 3:
      printf("Saindo do programa. Até logo!\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 3);
}
