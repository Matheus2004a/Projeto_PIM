#include <stdio.h>
#include <stdlib.h>

int questionario_obra()
{
  char nome[50], time[20];
  int idade;

  printf("Digite seu nome:");
  scanf("%s", &nome);

  printf("\n Digite sua idade: ");
  scanf("%d", &idade);

  printf("\n Qual o time voce torce?");
  scanf("%s", &time);

  // Defina o número de perguntas no questionário
  int numPerguntas = 6;

  // Crie um array para armazenar as respostas
  char respostas[numPerguntas][50]; // Pode ajustar o tamanho da resposta conforme necessário

  // Pergunte e armazene as respostas no array
  for (int i = 0; i < numPerguntas; i++)
  {
    printf("Digite a resposta para a pergunta %d: ", i + 1);
    scanf("%s", respostas[i]);

  }

  // Abra um arquivo para escrita
  FILE *arquivo;
  arquivo = fopen("respostas.txt", "w");

  // Verifique se o arquivo foi aberto com sucesso
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Escreva as respostas no arquivo
  for (int i = 0; i < numPerguntas; i++)
  {
    fprintf(arquivo, "De 0 a 10 como voce avaliaria a obra %d: %s\n", i + 1, respostas[i]);
    fprintf(arquivo, "Pergunta %d: %s\n", i + 1, respostas[i]);
    fprintf(arquivo, "Pergunta %d: %s\n", i + 1, respostas[i]);
  }

  // Feche o arquivo
  fclose(arquivo);

  printf("As respostas foram armazenadas no arquivo 'respostas.txt'.\n");

  return 0;
}
