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
void quickSort(int *vet, int ini, int fim);
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
  quickSort(vet1, 0, TAMANHO - 1);

  // Saída de dados
  // printf("\n\nOrdenado: \n\n");
   imprimirVetor(vet1);

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

void quickSort(int *vet, int ini, int fim) {
	int meio, pivo, topo, i;
	
	if (ini < fim) {
		pivo = vet[ini];
		topo = ini;
		
		for (i = ini + 1; i <= fim; i++) {
			if (vet[i] < pivo) {
				vet[topo] = vet[i];
				vet[i] = vet[topo + 1];
				topo++;
			}
		}
		
		vet[topo] = pivo;
		
		meio = topo;
		
		quickSort(vet, ini, meio);
		quickSort(vet, meio + 1, fim);
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
    {
      printf("\n");
    }
  }
}