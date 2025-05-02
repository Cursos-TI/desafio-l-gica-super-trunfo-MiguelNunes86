#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// guardar as informações da carta
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
    // criando duas cartas
    struct Carta carta1;
    struct Carta carta2;

    // primeira carta
    strcpy(carta1.estado, "SP");
    strcpy(carta1.cod, "001");
    strcpy(carta1.nome, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 230000000000.0;
    carta1.pontos = 15;

    // calculando densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPorPessoa = carta1.pib / carta1.populacao;

    // segunda carta
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.cod, "002");
    strcpy(carta2.nome, "Rio de Janeiro");
    carta2.populacao = 6000000;
    carta2.area = 1200.27;
    carta2.pib = 150000000000.0;
    carta2.pontos = 10;

    // calculando densidade e PIB per capita da carta 2
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPorPessoa = carta2.pib / carta2.populacao;

    // comparando a população das duas cartas
    printf("Comparando cartas (População):\n\n");
    printf("Carta 1 - %s (%s): %d pessoas\n", carta1.nome, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d pessoas\n", carta2.nome, carta2.estado, carta2.populacao);

    // vendo qual carta tem a maior população
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) ganhou!\n", carta1.nome);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) ganhou!\n", carta2.nome);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
