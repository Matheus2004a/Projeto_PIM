#include <stdio.h>
#include <stdlib.h>

#include "../dados_obra.h"
#include "../gerar_id.h"

void cadastrarObra()
{
  if (numObras < MAX_OBRAS)
  {
    obras[numObras].id = gerarIdAleatorio();

    printf("Digite o título da obra: ");
    getchar(); 
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
