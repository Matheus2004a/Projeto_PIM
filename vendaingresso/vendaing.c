#include <stdio.h>

#include "../obras/listagem/listar_obras.h"
#include "../obras/buscar_obra.h"
#include "../obras/dados_obra.h"
#include "../questionarios/visitantes/questionario_obra.h"
#include "../relatorios/relatorio_csv.h"

#define MAX_OBRAS 100
#define MAX_INGRESSOS 50

static int proximoID = 1;
static int ingressosVendidos[MAX_INGRESSOS];
static int quantidadeIngressos = 0;
static int ingressosDisponiveis = MAX_INGRESSOS;

int exibirMenu()
{
  int escolha;

  printf("Bem-vindo ao Museu!\n");
  printf("Escolha o tipo de ingresso:\n");
  printf("1. Ingresso normal - R$20\n");
  printf("2. Ingresso Estudante - R$10\n");
  printf("3. Ingresso para crianças/Idosos (Crianças até 12 anos) - Gratuito\n");
  printf("4. Sair\n");
  printf("Digite qual ingresso deseja: ");
  scanf("%d", &escolha);

  return escolha;
}

void validaObraTemIngresso(int *id)
{
  if (ingressosDisponiveis > 0)
  {
    *id = proximoID++;
    ingressosVendidos[quantidadeIngressos++] = *id;
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
  }

  return valor;
}

// Função p/ verificar se o ID escrito pelo usuário corresponde a um ingresso comprado
int verificarIdEntrada(int id)
{
  for (int i = 0; i < quantidadeIngressos; i++)
  {
    if (ingressosVendidos[i] == id)
    {
      return 1;
    }
  }

  printf("ID de ingresso inválido! Acesso negado.\n");
  return 0;
}

void verObraFinal(int id)
{
  int indice_obra;

  printf("Acesso à obra final permitido! Aproveite sua visita.\n");
  printf("Obra selecionada: \n");

  indice_obra = buscarObraPorId(id);

  if (indice_obra != -1)
  {
    obras[indice_obra].qtdVisitas += 1;

    printf("ID: %d \n", obras[indice_obra].id);
    printf("Título: %s \n", obras[indice_obra].titulo);
    printf("Descrição: %s \n", obras[indice_obra].descricao);
    printf("Autor: %s \n", obras[indice_obra].autor);
    printf("Ano: %d \n", obras[indice_obra].ano);
    printf("Qtd de visitas: %d \n", obras[indice_obra].qtdVisitas);

    generateCSVReport();
  }
}

int selecionaIdIngresso()
{
  listarObras();

  int id_ingresso, id_obra;

  printf("Digite o ID do ingresso para entrar na obra final: ");
  scanf("%d", &id_ingresso);

  if (verificarIdEntrada(id_ingresso))
  {
    printf("Digite o ID de uma obra pra mais detalhes: ");
    scanf("%d", &id_obra);
    verObraFinal(id_obra);
  }

  return 0;
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

  selecionaIdIngresso();

  return 0;
}
