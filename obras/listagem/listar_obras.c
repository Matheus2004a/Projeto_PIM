#include <stdio.h>

#include "../dados_obra.h"

void listarObras()
{
  printf("Lista de Obras Disponíveis:\n");

  if (numObras <= 0)
  {
    printf("Nenhuma obra cadastrada \n");
    return;
  }

  for (int i = 0; i < numObras; i++)
  {
    printf("\n");
    printf("ID: %d \n", obras[i].id);
    printf("Título: %s \n", obras[i].titulo);
    printf("Descrição: %s \n", obras[i].descricao);
    printf("Autor: %s \n", obras[i].autor);
    printf("Ano: %d \n", obras[i].ano);
    printf("\n\n");
  }
}

// Função que verifica se a ID escrita pelo usuário existe
int verificarIdExistente(int idEscolhida) {
  for (int i = 0; i < numObras; i++) {
    if (obras[i].id == idEscolhida) {
      // A ID existe, imprimir o título da obra
      printf("Você escolheu a obra: %s\n", obras[i].titulo);
      return 1; // Indica que a ID foi encontrada
    }
  }

  // Se a execução chegou aqui, a ID não foi encontrada
  printf("ID da obra não encontrada.\n");
  return 0; // Indica que a ID não foi encontrada
}

// Função para escolher a obra para ver
void escolherObraParaVer() {
  int idEscolhida;

  listarObras(); // Lista as obras disponíveis
  printf("Qual o ID da obra desejada? ");
  scanf("%d", &idEscolhida); // Captura a ID escolhida pelo usuário

  // Verifica se a ID existe e exibe o título da obra
  if (verificarIdExistente(idEscolhida)) {
    questionario_obra(); // Chama a função para o questionario
  }
}

