#include <stdio.h>

#define MAX_INGRESSOS 100

static int proximoID = 1;
static int ingressosVendidos[MAX_INGRESSOS];
static int quantidadeIngressos = 0;

int exibirMenu() {
    int escolha;

    printf("Bem-vindo ao Museu!\n");
    printf("Escolha o tipo de ingresso:\n");
    printf("1. Ingresso normal - R$20\n");
    printf("2. Ingresso Estudante - R$10\n");
    printf("3. Ingresso para criancas/Idosos (Crrincas ate 12 anos) - Gratuito\n");
    printf("4. Sair\n");
    printf("Digite o numero correspondente: ");
    scanf("%d", &escolha);

    return escolha;
}

float calcularValor(int escolha, int *id) {
    float valor = 0;

    switch (escolha) {
        case 1:
            valor = 20.0;
            ingressosVendidos[quantidadeIngressos++] = proximoID;
            *id = proximoID++;
            break;
        case 2:
            valor = 40.0;
            ingressosVendidos[quantidadeIngressos++] = proximoID;
            *id = proximoID++;
            break;
        case 3:
            printf("Ingresso gratuito para criancas!\n");
            *id = 0;
            break;
        default:
            printf("Escolha invalida.\n");
    }

    return valor;
}

int  fazerVendaIngresso() {
    int escolha, id;
    float total = 0;

    do {
        escolha = exibirMenu();

        if (escolha != 4) {
            float valor = calcularValor(escolha, &id);
            total += valor;
            if (escolha != 3) {
                printf("Ingresso adquirido! ID do ingresso: %d, Valor: R$%.2f\n", id, valor);
            }
        }
    } while (escolha != 4);

    printf("Ingressos adquiridos:\n");
    for (int i = 0; i < quantidadeIngressos; i++) {
        printf("Ingresso %d: ID %d\n", i + 1, ingressosVendidos[i]);
    }

    printf("Total a pagar: R$%.2f\n", total);
    printf("Obrigado por visitar o museu!\n");

    return 0;
}