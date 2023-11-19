#include "dados_obra.h"

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
