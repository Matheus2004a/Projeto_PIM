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
  char nome[50];
  int resposta1, resposta2, resposta3;

  printf("Qual é o seu nome? ");
  scanf("%s", nome);

  printf("\nPergunta 1: O que você achou da obra?\n");
  printf("1 - Bom\n2 - Regular\n3 - Ruim\nEscolha a sua resposta: ");
  scanf("%d", &resposta1);
  registrarRespostasNoArquivo("O que você achou da obra", obterOpcao(resposta1));

  printf("\nPergunta 2: Você recomendaria para outras pessoas visitar o museu?\n");
  printf("1 - Sim\n2 - Não\nEscolha a sua resposta: ");
  scanf("%d", &resposta2);
  registrarRespostasNoArquivo("Você recomendaria para outras pessoas visitar o museu?", (resposta2 == 1) ? "Sim" : "Não");

  printf("\nPergunta 3: Qual sua opinião dos valores do ingresso?\n");
  printf("1 - Excelente\n2 - Da para melhorar\n3 - Muito caro!\nEscolha a sua resposta: ");
  scanf("%d", &resposta3);
  registrarRespostasNoArquivo("Qual sua opinião dos valores do ingresso", (resposta3 == 1) ? "Excelente" : (resposta3 == 2) ? "Da para melhorar"
                                                                                                                            : "Muito caro!");

  printf("\nObrigado por responder o Questionario.\n");

  return 0;
}
