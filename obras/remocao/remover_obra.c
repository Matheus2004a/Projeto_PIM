#include <stdio.h>

#include "../dados_obra.h"
#include "../buscar_obra.h"

int removerObra(int id)
{
  int indice = buscarObraPorId(id);

  if (indice != -1)
  {
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
