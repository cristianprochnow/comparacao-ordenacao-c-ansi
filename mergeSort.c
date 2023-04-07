/*
EQUIPE
NOMES:

CONSEGUIU CHEGAR NO RESULTADO?
R:

SE NÃO, POR QUE NÃO CONSEGUIU CHEGAR NO RESULTADO?
R.:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000

// Prototipo de Função
void geraNumero(int *vet, int op);
void mergeSort(int *vet, int ini, int fim, int *qtd_trocas, int *qtd_comparacoes);
void imprimirVetor(int *vet);

int main(void)
{
  // Variáveis
  int vet1[TAMANHO];

  float tempo_inicial = clock();

  int qtd_trocas = 0;
  int qtd_comparacoes = 0;

  int *qtd_trocas_aux = &qtd_trocas;
  int *qtd_comparacoes_aux = &qtd_comparacoes;

  // Entrada de dados;
  geraNumero(vet1, 3);
  // printf("Desordenado: \n\n");
  // imprimirVetor(vet1);

  // Processamentos dos dados
  mergeSort(vet1, 0, TAMANHO - 1, qtd_trocas_aux, qtd_comparacoes_aux);

  // Saída de dados
  // printf("\n\nOrdenado: \n\n");
  // imprimirVetor(vet1);

  // Ponto do algoritmo para calcular o tempo de execução
  float tempo_final = clock() - tempo_inicial;

  // Saída de dados
  printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
  printf("Quantidade de trocas: %i\n", qtd_trocas);
  printf("Tempo de execucao do algoritmo: %.3f", tempo_final / 1000);

  return 0;
}

// Função geração de números
void geraNumero(int *vet, int op)
{
  int i, j;

  switch (op)
  {
  case 1: // Ordenados
    for (i = 0; i < TAMANHO; i++)
      vet[i] = i + 1;
    break;

  case 2: // Invertidos
    for (i = 0; i < TAMANHO; i++)
      vet[i] = TAMANHO - i;
    break;

  case 3: // Aleatórios
    for (i = 0; i < TAMANHO; i++)
      vet[i] = (int)(rand() % TAMANHO);
    break;
  }
}

// Função Merge Sort
void mergeSort(int *vet, int inicio, int fim, int *qtd_trocas, int *qtd_comparacoes)
{
  if (inicio < fim)
  {
    int meio = (inicio + fim) / 2;

    mergeSort(vet, inicio, meio, qtd_trocas, qtd_comparacoes);
    mergeSort(vet, meio + 1, fim, qtd_trocas, qtd_comparacoes);

    int tam_esq = meio - inicio + 1;
    int tam_dir = fim - meio;

    int esq[tam_esq], dir[tam_dir];

    for (int i = 0; i < tam_esq; i++)
      esq[i] = vet[inicio + i];

    for (int j = 0; j < tam_dir; j++)
      dir[j] = vet[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < tam_esq && j < tam_dir)
    {
      *qtd_comparacoes += 1;
      if (esq[i] <= dir[j])
      {
        vet[k] = esq[i];
        i++;
      }
      else
      {
        vet[k] = dir[j];
        j++;
      }
      k++;
      *qtd_trocas += 1;
    }

    while (i < tam_esq)
    {
      vet[k] = esq[i];
      i++;
      k++;
      *qtd_trocas += 1;
    }

    while (j < tam_dir)
    {
      vet[k] = dir[j];
      j++;
      k++;
      *qtd_trocas += 1;
    }
  }
}

// Função impressão do vetor
void imprimirVetor(int *vet)
{
  int i;

  for (i = 0; i < TAMANHO; i++)
  {
    printf("%i, ", vet[i]);

    if ((i + 1) % 14 == 0)
      printf("\n");
  }
}