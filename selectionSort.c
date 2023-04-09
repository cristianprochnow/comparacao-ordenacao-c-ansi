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
void selectionSort(int *vet);
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
  selectionSort(vet1);

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

void selectionSort(int *vet)
{
  int n, troca, i, aux, qtd_trocas, qtd_comparacoes;

  n = 1;
  troca = 1;
  qtd_trocas = 0;
  qtd_comparacoes = 0;

  // Ponto do algoritmo para iniciar o tempo de execução
  float tempo_inicial = clock();

  int vMenor;
  int vAux;
  int vTemp;
  int vTroca;
  int pVetor[TAMANHO];

  for(vAux=0; vAux < TAMANHO-1; vAux++)
  {
    vMenor = vAux;

    for (vTemp=vAux+1; vTemp < TAMANHO; vTemp++)
    {
      qtd_comparacoes++;
      if (vet[vTemp] < vet[vMenor])
      {
        vMenor = vTemp;
      }
    }

    if (vMenor != vAux)
    {
      vTroca      = vet[vAux];
      vet[vAux]   = pVetor[vMenor];
      vet[vMenor] = vTroca;

      qtd_trocas++;
    }
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