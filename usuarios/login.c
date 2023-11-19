#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuarios.h"
#include "../menuVisitante/visitantes.h"
#include "../obras/obras.h"

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
      if (strcmp(username, "Admin") == 0)
      {
        printf("Logado como Admin \n");
        system("cls");
        administraObras();
      }
      else
      {
        printf("Login feito com sucesso \n");
        system("cls");
        escolherObras();
      }

      return i;
    }
  }

  return -1;
}
