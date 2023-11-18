#ifndef DADOS_USUARIOS_H
#define DADOS_USUARIOS_H

#define MAX_USUARIOS 100

typedef struct
{
  char username[50];
  char password[50];
  char nivelAcesso[20];
} Usuario;

extern Usuario usuarios[MAX_USUARIOS];
extern int numUsuarios;

#endif
