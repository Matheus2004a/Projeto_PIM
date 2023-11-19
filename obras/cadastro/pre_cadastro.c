#include <stdio.h>
#include <string.h>

#include "../dados_obra.h"
#include "../gerar_id.h"

void preCadastrarObra(const char *titulo, const char *descricao, const char *autor, int anoPublic)
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

void preSaveObra()
{
  preCadastrarObra(
      "Pele, o rei do futebol",
      "Edson Arantes do Nascimento, mais conhecido como Pelé, foi um futebolista brasileiro que atuou como atacante/Rei do Futebol.",
      "Edson Pele",
      2000);

  preCadastrarObra(
      "Santos FC",
      "O Santos Futebol Clube, mais conhecido como Santos, é um clube poliesportivo brasileiro",
      "Celso Unzelte",
      2012);

  preCadastrarObra(
      "SPFC",
      "O São Paulo Futebol Clube, é um clube poliesportivo brasileiro da cidade de São Paulo",
      "Cauã",
      2023);
}
