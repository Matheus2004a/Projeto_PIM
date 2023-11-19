#include <stdio.h>
#include <string.h>

#include "usuarios.h"

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

void cadastrarUsuario()
{
  char novoUsername[50];

  printf("Digite o nome de usuario: ");
  scanf("%s", novoUsername);

  if (verificarUsuarioExistente(novoUsername))
  {
    printf("Usuario ja cadastrado. Por favor, escolha outro.\n");
    return;
  }

  if (numUsuarios < MAX_USUARIOS)
  {
    strcpy(usuarios[numUsuarios].username, novoUsername);

    printf("Digite a senha: ");
    scanf("%s", usuarios[numUsuarios].password);

    if (strcmp(novoUsername, "Admin") == 0)
    {
      strcpy(usuarios[numUsuarios].nivelAcesso, "admin");
    }

    printf("Usuario cadastrado com sucesso \n");
    numUsuarios++;
  }
  else
  {
    printf("Limite de usuarios atingido!\n");
  }
}
