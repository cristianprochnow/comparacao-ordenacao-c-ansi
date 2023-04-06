#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000

// Protótipos de Função
void geraNumero(int *vet, int op);
void insertionSort(int *vet);
void imprimirVetor(int *vet);

int main() {
    // Variáveis
    int vet1[TAMANHO];

    // Entrada de dados;
    geraNumero(vet1, 3);
    // printf("Desordenado: \n\n");
    // imprimirVetor(vet1);

    // Processamento dos dados
    insertionSort(vet1);

    // Saída de dados
    // printf("\n\nOrdenado: \n\n");
    // imprimirVetor(vet1);

    return 0;
}

// Função geração de números
void geraNumero(int *vet, int op) {
    int i, j;

    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = i + 1;
            }
            break;
        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = TAMANHO - i;
            }
            break;
        case 3: // Aleatórios
            srand(time(NULL));
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = rand() % TAMANHO;
            }
            break;
    }
}

// Função ordenação insertion sort
void insertionSort(int *vet) {
    int i, j, atual, qtd_trocas = 0, qtd_comparacoes = 0;

    // Ponto do algoritmo para iniciar o tempo de execução
    float tempo_inicial = clock();

    for (i = 1; i < TAMANHO; i++) {
        atual = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > atual) {
            // Ponto do algoritmo para contar as comparações
            qtd_comparacoes++;

            vet[j + 1] = vet[j];
            j = j - 1;
            // Ponto do algoritmo para contar as trocas
            qtd_trocas++;
        }
        vet[j + 1] = atual;
    }

    // Ponto do algoritmo para calcular o tempo de execução
    float tempo_final = clock() - tempo_inicial;

    // Saída de dados
    printf("Quantidade de comparacoes: %i\n", qtd_comparacoes);
    printf("Quantidade de trocas: %i\n", qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n", tempo_final / CLOCKS_PER_SEC);
}

// Função impressão do vetor
void imprimirVetor(int *vet) {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        printf("%i, ", vet[i]);
        if ((i + 1) % 14 == 0) {
            printf("\n");
        }
    }
}
