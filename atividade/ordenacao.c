#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int ordenado(int list[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (list[i] > list[i + 1])
        {
            return 0;
        }
    return 1;
}

void selecao(int list[], int n)
{
    int i, j, indice_min, aux;

    for (i = 0; i < n - 1; i++)
    {
        indice_min = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[indice_min])
            {
                indice_min = j;
            }
        }

        if (indice_min != i)
        {
            aux = list[i];
            list[i] = list[indice_min];
            list[indice_min] = aux;
        }
    }
}

void insercao(int list[], int n)
{
    for (size_t i = 1; i < n; i++)
    {
        int current = list[i];
        int prev = i - 1;

        while (prev >= 0 && current < list[prev])
        {
            list[prev + 1] = list[prev];
            prev--;
        }

        list[prev + 1] = current;
    }
}

void merge(int list[], int inicio, int meio, int fim)
{
    int left = meio - inicio + 1;
    int right = fim - meio;

    int *listLeft = (int *)malloc(left * sizeof(int));
    int *listRight = (int *)malloc(right * sizeof(int));

    for (int i = 0; i < left; i++)
    {
        listLeft[i] = list[inicio + i];
    }
    for (int i = 0; i < right; i++)
    {
        listRight[i] = list[meio + 1 + i];
    }

    int i = 0, j = 0, k = inicio;

    while (i < left && j < right)
    {
        if (listLeft[i] <= listRight[j])
        {
            list[k] = listLeft[i];
            i++;
        }
        else
        {
            list[k] = listRight[j];
            j++;
        }
        k++;
    }

    while (i < left)
    {
        list[k] = listLeft[i];
        i++;
        k++;
    }

    while (j < right)
    {
        list[k] = listRight[j];
        j++;
        k++;
    }

    free(listLeft);
    free(listRight);
}
void merge(int list[], int inicio, int meio, int fim);

void mergeSort(int list[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(list, inicio, meio);
        mergeSort(list, meio + 1, fim);

        merge(list, inicio, meio, fim);
    }
}