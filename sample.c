/*
EQUIPE
NOMES:

CONSEGUIU CHEGAR NO RESULTADO?
R:

SE NÃO, POR QUE NÃO CONSEGUIU CHEGAR NO RESULTADO?
R.:
*/

#include <stdio.h>
#include <time.h>

#define TAMANHO 10000

// Prototipo de Função
void geraNumero(int *vet, int op);
void bubbleSort(int *vet);
void imprimirVetor(int *vet);

int main(void)
{
  // Variáveis
  int vet1[TAMANHO];

  // Entrada de dados;
  geraNumero(vet1, 3);
  // printf("Desordenado: \n\n");
  // imprimirVetor(vet1);

  // Processamentos dos dados
  bubbleSort(vet1);

  // Saída de dados
  // printf("\n\nOrdenado: \n\n");
  // imprimirVetor(vet1);

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
    {
      vet[i] = i + 1;
    }
    break;

  case 2: // Invertidos
    for (i = 0; i < TAMANHO; i++)
    {
      vet[i] = TAMANHO - i;
    }
    break;

  case 3: // Aleatórios
    for (i = 0; i < TAMANHO; i++)
    {
      vet[i] = (int)(rand() % TAMANHO);
    }
    break;
  }
}

// Função ordenação bubble sort
void bubbleSort(int *vet)
{
  int n, troca, i, aux, qtd_trocas, qtd_comparacoes;

  n = 1;
  troca = 1;
  qtd_trocas = 0;
  qtd_comparacoes = 0;

  // Ponto do algoritmo para iniciar o tempo de execução
  float tempo_inicial = clock();

  while (n <= TAMANHO && troca == 1)
  {
    troca = 0;

    for (i = 0; i <= TAMANHO - 2; i++)
    {
      // Ponto do algoritmo para contar as comparações
      qtd_comparacoes++;

      if (vet[i] > vet[i + 1])
      {
        // Ponto do algoritmo para contar as trocas
        qtd_trocas++;
        troca = 1;
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
      }
    }

    n = n + 1;
  }

  // Ponto do algoritmo para calcular o tempo de execução
  float tempo_final = clock() - tempo_inicial;

  // Saída de dados
  printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
  printf("Quantidade de trocas: %i\n", qtd_trocas);
  printf("Tempo de execucao do algoritmo: %.3f", tempo_final / 1000);
}

// Função impressão do vetor
void imprimirVetor(int *vet)
{
  int i;

  for (i = 0; i < TAMANHO; i++)
  {
    printf("%i, ", vet[i]);

    if ((i + 1) % 14 == 0)
    {
      printf("\n");
    }
  }
}