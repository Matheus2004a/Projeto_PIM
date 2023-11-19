#include <stdio.h>
#include <string.h>

#include "../dados_obra.h"
#include "../buscar_obra.h"

int editarObra(int id)
{
  int indice = buscarObraPorId(id);

  if (indice != -1)
  {
    printf("Editando obra com ID %d:\n", id);

    printf("Novo Título: ");
    getchar();
    fgets(obras[indice].titulo, sizeof(obras[indice].titulo), stdin);
    obras[indice].titulo[strcspn(obras[indice].titulo, "\n")] = '\0'; // Remover a nova linha do final

    printf("Nova Descrição: ");
    getchar();
    fgets(obras[indice].descricao, sizeof(obras[indice].descricao), stdin);
    obras[indice].descricao[strcspn(obras[indice].descricao, "\n")] = '\0';

    printf("Novo Autor: ");
    getchar();
    fgets(obras[indice].autor, sizeof(obras[indice].autor), stdin);
    obras[indice].autor[strcspn(obras[indice].autor, "\n")] = '\0';

    printf("Novo Ano: ");
    scanf("%d", &obras[indice].ano);

    printf("Obra editada com sucesso.\n");
  }
  else
  {
    printf("ID de obra não encontrado.\n");
  }
}
