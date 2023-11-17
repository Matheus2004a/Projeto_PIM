#include <stdio.h>
#include <stdlib.h>

// Função para obter a opção correspondente à resposta
const char *obterOpcao(int resposta)
{
  switch (resposta)
  {
  case 1:
    return "Bom";
  case 2:
    return "Regular";
  case 3:
    return "Ruim";
  default:
    return "Opção inválida";
  }
}

void registrarRespostasNoArquivo(const char *pergunta, const char *resposta)
{
  FILE *arquivo;
  arquivo = fopen("respostas.txt", "a");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  fprintf(arquivo, "%s: %s\n", pergunta, resposta);

  fclose(arquivo);
}

int questionario_obra()
{
  // Declaração de variáveis
  char nome[50];
  int resposta1, resposta2, resposta3;

  // Pergunta 1: Nome
  printf("Qual é o seu nome? ");
  scanf("%s", nome);

  // Pergunta 2: O que você achou da obra?
  printf("\nPergunta 1: O que você achou da obra?\n");
  printf("1 - Bom\n2 - Regular\n3 - Ruim\nEscolha a sua resposta: ");
  scanf("%d", &resposta1);
  registrarRespostasNoArquivo("O que você achou da obra", obterOpcao(resposta1));

  // Pergunta 3: Você recomendaria para outras pessoas visitar o museu?
  printf("\nPergunta 2: Você recomendaria para outras pessoas visitar o museu?\n");
  printf("1 - Sim\n2 - Não\nEscolha a sua resposta: ");
  scanf("%d", &resposta2);
  registrarRespostasNoArquivo("Você recomendaria para outras pessoas visitar o museu?", (resposta2 == 1) ? "Sim" : "Não");

  // Pergunta 4: Qual sua opinião dos valores do ingresso?
  printf("\nPergunta 3: Qual sua opinião dos valores do ingresso?\n");
  printf("1 - Excelente\n2 - Da para melhorar\n3 - Muito caro!\nEscolha a sua resposta: ");
  scanf("%d", &resposta3);
  registrarRespostasNoArquivo("Qual sua opinião dos valores do ingresso", (resposta3 == 1) ? "Excelente" : (resposta3 == 2) ? "Da para melhorar"
                                                                                                                            : "Muito caro!");

  printf("\nRespostas armazenadas com sucesso no arquivo 'respostas.txt'.\n");

  return 0;
}
