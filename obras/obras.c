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

int buscarObraPorId(int id)
{
  for (int i = 0; i < numObras; i++)
  {
    if (obras[i].id == id)
    {
      return i;
    }
  }

  return -1;
}

void editarObra()
{
  int id;

  printf("Digite o ID da obra que deseja editar: ");
  scanf("%d", &id);

  int indice = buscarObraPorId(id);

  if (indice != -1)
  {
    printf("Editando obra com ID %d:\n", id);

    printf("Novo Título: ");
    getchar();
    fgets(obras[indice].titulo, sizeof(obras[indice].titulo), stdin);
    obras[indice].titulo[strcspn(obras[indice].titulo, "\n")] = '\0'; // Remover a nova linha do final

    printf("Nova Descrição: ");
    getchar();
    fgets(obras[indice].descricao, sizeof(obras[indice].descricao), stdin);
    obras[indice].descricao[strcspn(obras[indice].descricao, "\n")] = '\0';

    printf("Novo Autor: ");
    getchar();
    fgets(obras[indice].autor, sizeof(obras[indice].autor), stdin);
    obras[indice].autor[strcspn(obras[indice].autor, "\n")] = '\0';

    printf("Novo Ano: ");
    scanf("%d", &obras[indice].ano);

    printf("Obra editada com sucesso.\n");
  }
  else
  {
    printf("ID de obra não encontrado.\n");
  }
}

void removerObra()
{
  int id;

  printf("Digite o ID da obra que deseja remover: ");
  scanf("%d", &id);

  int indice = buscarObraPorId(id);

  if (indice != -1)
  {
    // Desloca os elementos à esquerda para preencher o espaço do elemento removido
    for (int i = indice; i < numObras - 1; i++)
    {
      obras[i] = obras[i + 1];
    }

    numObras--;

    printf("Obra removida com sucesso.\n");
  }
  else
  {
    printf("Obra não encontrada.\n");
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
      editarObra();
      break;
    case 3:
      removerObra();
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
