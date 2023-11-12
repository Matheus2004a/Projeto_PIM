#define MAX_USUARIOS 100

typedef struct
{
  char username[50];
  char password[50];
  char nivelAcesso[20];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

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
    return; // Retorna sem cadastrar o usuário
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
