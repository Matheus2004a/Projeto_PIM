#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarIdAleatorio()
{
  static int geradorInicial = 0;

  if (!geradorInicial)
  {
    srand((unsigned int)time(NULL));
    geradorInicial = 1;
  }

  return rand();
}

void listarObras()
{
  printf("Lista de Obras Disponíveis:\n");

  if (numObras <= 0)
  {
    return printf("Nenhuma obra cadastrada \n");
  }

  for (int i = 0; i < numObras; i++)
  {
    printf("\n");
    printf("ID: %d \n", obras[i].id);
    printf("Título: %s \n", obras[i].titulo);
    printf("Descrição: %s \n", obras[i].descricao);
    printf("Autor: %s \n", obras[i].autor);
    printf("Ano: %d \n", obras[i].ano);
    printf("\n\n");
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

int editarObra(int id)
{
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

int removerObra(int id)
{
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

void preCadastrarObra(const char * titulo, const char * descricao, const char * autor, int anoPublic)
{
  if (numObras > MAX_OBRAS)
  {
    printf("Limite de obras atingido!\n");
    return;
  }

  obras[numObras].id = gerarIdAleatorio();
  strcpy(obras[numObras].titulo, titulo);
  strcpy(obras[numObras].descricao, descricao);
  strcpy(obras[numObras].autor, autor);
  obras[numObras].ano = anoPublic;

  numObras++;
}

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
