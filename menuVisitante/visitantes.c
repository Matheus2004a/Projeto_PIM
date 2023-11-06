#include <stdio.h>
#include <stdlib.h>

void listarObrasDisponiveis()
{
  printf("Lista de Obras Disponíveis:\n");
  printf("Obra 1\n");
  printf("Obra 2\n");
}

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
      listarObrasDisponiveis();
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
