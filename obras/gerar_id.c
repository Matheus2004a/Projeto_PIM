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
