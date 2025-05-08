#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3];
    char cod[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pibPorPessoa;
};

int main() {
    struct Carta carta1, carta2;

    // Carta 1
    strcpy(carta1.estado, "SP");
    strcpy(carta1.cod, "001");
    strcpy(carta1.nome, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 230000000000.0;
    carta1.pontos = 15;
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPorPessoa = carta1.pib / carta1.populacao;

    // Carta 2
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.cod, "002");
    strcpy(carta2.nome, "Rio de Janeiro");
    carta2.populacao = 6000000;
    carta2.area = 1200.27;
    carta2.pib = 150000000000.0;
    carta2.pontos = 10;
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPorPessoa = carta2.pib / carta2.populacao;

    int escolha1, escolha2;

    printf("Escolha dois atributos diferentes para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade demográfica\n");
    printf("5 - PIB per capita\n");

    printf("\nDigite o número do primeiro atributo: ");
    scanf("%d", &escolha1);
    while (escolha1 < 1 || escolha1 > 5) {
        printf("Escolha inválida. Tente novamente: ");
        scanf("%d", &escolha1);
    }

    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Densidade demográfica\n"); break;
                case 5: printf("5 - PIB per capita\n"); break;
            }
        }
    }

    printf("Digite o número do segundo atributo: ");
    scanf("%d", &escolha2);
    while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Escolha inválida. Tente novamente: ");
        scanf("%d", &escolha2);
    }

    float v1c1 = 0, v1c2 = 0, v2c1 = 0, v2c2 = 0;

    // Pegando os valores do primeiro atributo
    if (escolha1 == 1) { v1c1 = carta1.populacao; v1c2 = carta2.populacao; }
    else if (escolha1 == 2) { v1c1 = carta1.area; v1c2 = carta2.area; }
    else if (escolha1 == 3) { v1c1 = carta1.pib; v1c2 = carta2.pib; }
    else if (escolha1 == 4) { v1c1 = carta1.densidade; v1c2 = carta2.densidade; }
    else if (escolha1 == 5) { v1c1 = carta1.pibPorPessoa; v1c2 = carta2.pibPorPessoa; }

    // Pegando os valores do segundo atributo
    if (escolha2 == 1) { v2c1 = carta1.populacao; v2c2 = carta2.populacao; }
    else if (escolha2 == 2) { v2c1 = carta1.area; v2c2 = carta2.area; }
    else if (escolha2 == 3) { v2c1 = carta1.pib; v2c2 = carta2.pib; }
    else if (escolha2 == 4) { v2c1 = carta1.densidade; v2c2 = carta2.densidade; }
    else if (escolha2 == 5) { v2c1 = carta1.pibPorPessoa; v2c2 = carta2.pibPorPessoa; }

    // Comparação individual
    int pontos1 = 0, pontos2 = 0;

    if (escolha1 == 4) { 
        if (v1c1 < v1c2) pontos1++;
        else if (v1c2 < v1c1) pontos2++;
    } else {
        if (v1c1 > v1c2) pontos1++;
        else if (v1c2 > v1c1) pontos2++;
    }

    if (escolha2 == 4) {
        if (v2c1 < v2c2) pontos1++;
        else if (v2c2 < v2c1) pontos2++;
    } else {
        if (v2c1 > v2c2) pontos1++;
        else if (v2c2 > v2c1) pontos2++;
    }

    float soma1 = v1c1 + v2c1;
    float soma2 = v1c2 + v2c2;

    // Exibindo resultados
    printf("\n--- Resultado da Rodada ---\n");
    printf("%s - %.2f + %.2f = %.2f\n", carta1.nome, v1c1, v2c1, soma1);
    printf("%s - %.2f + %.2f = %.2f\n", carta2.nome, v1c2, v2c2, soma2);

    if (soma1 > soma2) {
        printf("\n%s venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("\n%s venceu!\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
