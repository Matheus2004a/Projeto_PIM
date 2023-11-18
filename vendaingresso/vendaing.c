#include <stdio.h>

#include "obras/dados_obra.h"

#define MAX_INGRESSOS 3

static int proximoID = 1;
static int ingressosVendidos[MAX_INGRESSOS];
static int quantidadeIngressos = 0;
static int ingressosDisponiveis = MAX_INGRESSOS;

#define MAX_OBRAS 100


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
    fazerVendaIngresso();
  }
}

int exibirMenu()
{
  int escolha;

  printf("Bem-vindo ao Museu!\n");
  printf("Escolha o tipo de ingresso:\n");
  printf("1. Ingresso normal - R$20\n");
  printf("2. Ingresso Estudante - R$10\n");
  printf("3. Ingresso para criancas/Idosos (Criancas ate 12 anos) - Gratuito\n");
  printf("4. Sair\n");
  printf("Digite qual ingressso deseja: ");
  scanf("%d", &escolha);

  return escolha;
}

void validaObraTemIngresso(int *id)
{
  if (ingressosDisponiveis > 0)
  {
    // Armazena o ID do ingresso vendido
    ingressosVendidos[quantidadeIngressos++] = proximoID;
    // Decrementa o número de ingressos disponíveis
    ingressosDisponiveis--;
  }
  else
  {
    printf("Ingressos esgotados!\n");
    *id = 0;
  }
}

float calcularValor(int escolha, int *id)
{
  float valor = 0;

  switch (escolha)
  {
  case 1:
    valor = 20.0;
    break;
  case 2:
    valor = 10.0;
    break;
  case 3:
    printf("Ingresso gratuito para crianças!\n");
    break;
  default:
    printf("Escolha inválida.\n");
    return 0;
  }

  // Atribui o ID e decrementa o número de ingressos disponíveis apenas para casos diferentes de 3
  if (escolha <= 3)
  {
    validaObraTemIngresso(id);
    ingressosVendidos[quantidadeIngressos++] = *id;
    *id = proximoID++;
  }

  return valor;
}

int fazerVendaIngresso()
{
  int escolha, id;
  float total = 0;

  do
  {
    escolha = exibirMenu();

    if (escolha != 4)
    {
      float valor = calcularValor(escolha, &id);
      total += valor;

      if (escolha != 3)
      {
        printf("Ingresso adquirido! ID do ingresso: %d, Valor: R$%.2f\n", id, valor);
      }
    }
  } while (escolha != 4);

  printf("Ingressos adquiridos:\n");
  for (int i = 0; i < quantidadeIngressos; i++)
  {
    printf("Ingresso %d: ID %d\n", i + 1, ingressosVendidos[i]);
  }

  printf("Total a pagar: R$%.2f\n", total);
  printf("Obrigado por visitar o museu!\n");

  escolherObraParaVer();

  return 0;
}
