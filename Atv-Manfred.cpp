#include <stdio.h> 
#include <math.h>
#include <time.h> 

 

#define TAMANHO 10000 

 

// Prototipo de Fun��o 

void geraNumero(int *vet, int op); 

void fSelect_Sort(int *vet);

void imprimirVetor(int *vet); 

 

int main (void){ 

// Vari�veis 

int vet1[TAMANHO]; 

 

// Entrada de dados; 

geraNumero(vet1,3); 

// printf("Desordenado: \n\n"); 

// imprimirVetor(vet1); 

 

// Processamentos dos dados 

SelectSort(vet1);

 

// Sa�da de dados 

 printf("\n\nOrdenado: \n\n"); 

imprimirVetor(vet1); 

return 0; 

} 

 

// Fun��o gera��o de n�meros 

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

               vet[i] = TAMANHO-i; 

            } 

            break; 

        case 3: // Aleat�rios 

            for (i = 0; i < TAMANHO; i++) { 

                vet[i] = (int) (rand() % TAMANHO); 

            } 

            break; 

    } 

 

} 


void SelectSort(int *vet)
{
    int vMenor;
    int vAux;
    int vTemp;
    int vTroca;

    for(vAux=0; vAux < TAMANHO-1; vAux++) 
    {
        vMenor = vAux; 

        for (vTemp=vAux+1; vTemp < TAMANHO; vTemp++) 
        {
            if (*vet[vTemp] < *vet [vMenor])
            {
                vMenor = vTemp; 
            }
        }

        if (vMenor != vAux) 
        {
            vTroca         = *vet[vAux];
            *vet[vAux]   = pVetor[vMenor];
            *vet[vMenor] = vTroca;
        }
    }
}
 

// Fun��o impress�o do vetor 

void imprimirVetor(int *vet){ 

int i; 

for(i=0;i<TAMANHO;i++){ 

printf("%i, ",vet[i]); 

if ((i+1)%14 == 0){ 

printf("\n"); 

} 

} 

} 
