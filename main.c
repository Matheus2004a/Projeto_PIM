#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "obras/obras.h"
#include "menu/menu.h"

#define MAX_USUARIOS 100
#define MAX_OBRAS 100

typedef struct
{
  char username[50];
  char password[50];
  char nivelAcesso[20];
} Usuario;

typedef struct
{
  char titulo[100];
  char descricao[400];
  char autor[50];
  int ano;
} Obra;

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

Obra obras[MAX_OBRAS];
int numObras = 0;

int verificarUsuarioExistente(char *username)
{
  for (int i = 0; i < numUsuarios; i++)
  {
    if (strcmp(username, usuarios[i].username) == 0)
    {
      return 1; // Retorna 1 se o usuário já existe
    }
  }
  return 0; // Retorna 0 se o usuário não existe
}

void cadastrarObra()
{
  if (numObras < MAX_OBRAS)
  {
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

    numObras++;
  }
  else
  {
    printf("Limite de obras atingido!\n");
  }
}

void cadastrarUsuario()
{
  char novoUsername[50];

  printf("Digite o nome de usuario: ");
  scanf("%s", novoUsername);

  if (verificarUsuarioExistente(novoUsername))
  {
    printf("Usuario ja cadastrado. Por favor, escolha outro.\n");
    return; // Retorna sem cadastrar o usuário
  }

  if (numUsuarios < MAX_USUARIOS)
  {
    strcpy(usuarios[numUsuarios].username, novoUsername);

    printf("Digite a senha: ");
    scanf("%s", usuarios[numUsuarios].password);

    if (strcmp(novoUsername, "Matheus") == 0)
    {
      strcpy(usuarios[numUsuarios].nivelAcesso, "admin");
      printf("Usuario cadastrado com sucesso \n");
      administraObras();
    }

    numUsuarios++;
  }
  else
  {
    printf("Limite de usuarios atingido!\n");
  }
}

int fazerLogin()
{
  char username[50];
  char password[50];

  printf("Digite o nome de usuario: ");
  scanf("%s", username);

  printf("Digite a senha: ");
  scanf("%s", password);

  for (int i = 0; i < numUsuarios; i++)
  {
    if (strcmp(username, usuarios[i].username) == 0 && strcmp(password, usuarios[i].password) == 0)
    {
      return i;
    }
  }

  return -1;
}

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
