# Comparação de Performance de Métodos de Ordenação
## Equipe
- Cristian Prochnow
- Gustavo Henrique Dias
- Lucas Willian de Souza Serpa
- Marlon de Souza
- Ryan Gabriel Mazzei Bromati

# Algoritmos
## Insertion Sort
![insertion-sort]
```c
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
```

## Selection Sort
![selection-sort]
```c
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
```

## Merge Sort
![merge-sort]
```c
float tempo_inicial = clock();

int qtd_trocas = 0;
int qtd_comparacoes = 0;

int *qtd_trocas_aux = &qtd_trocas;
int *qtd_comparacoes_aux = &qtd_comparacoes;

geraNumero(vet1, 3);
mergeSort(vet1, 0, TAMANHO - 1, qtd_trocas_aux, qtd_comparacoes_aux);

float tempo_final = clock() - tempo_inicial;

printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
printf("Quantidade de trocas: %i\n", qtd_trocas);
printf("Tempo de execucao do algoritmo: %.3f", tempo_final / 1000);

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
```

## Quick Sort
![quick-sort]
```c
float tempo_inicial = clock();

int qtd_trocas = 0;
int qtd_comparacoes = 0;

int *qtd_trocas_aux = &qtd_trocas;
int *qtd_comparacoes_aux = &qtd_comparacoes;

geraNumero(vet1, 3);
quickSort(vet1, 0, TAMANHO - 1, qtd_trocas_aux, qtd_comparacoes_aux);

float tempo_final = clock() - tempo_inicial;

printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
printf("Quantidade de trocas: %i\n", qtd_trocas);
printf("Tempo de execucao do algoritmo: %.3f", tempo_final / 1000);

void quickSort(int *vet, int ini, int fim, int *qtd_trocas, int *qtd_comparacoes) {
	int meio, pivo, topo, i;

	if (ini < fim) {
		pivo = vet[ini];
		topo = ini;

		for (i = ini + 1; i <= fim; i++) {
			*qtd_comparacoes += 1;
			if (vet[i] < pivo) {
				vet[topo] = vet[i];
				vet[i] = vet[topo + 1];
				topo++;

				*qtd_trocas += 1;
			}
		}

		vet[topo] = pivo;

		meio = topo;

		quickSort(vet, ini, meio, qtd_trocas, qtd_comparacoes);
		quickSort(vet, meio + 1, fim, qtd_trocas, qtd_comparacoes);
	}
}
```

## Bubble Sort
![bubble-sort]
```c
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
```

[bubble-sort]: ./images/bubbleSort.png
[insertion-sort]: ./images/insertionSort.png
[selection-sort]: ./images/selectionSort.png
[merge-sort]: ./images/mergeSort.png
[quick-sort]: ./images/quickSort.png