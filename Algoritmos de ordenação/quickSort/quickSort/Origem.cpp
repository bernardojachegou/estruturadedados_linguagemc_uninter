#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Prot�tipo da fun��o de ordena��o
void quick_sort(int* a, int left, int right);

// Fun��o main
int main(int argc, char** argv)
{
    int i, vet[MAX];

    // L� MAX ou 10 valores
    for (i = 0; i < MAX; i++)
    {
        printf("Digite um valor: ");
        scanf_s("%d", &vet[i]);
    }

    // Ordena os valores
    quick_sort(vet, 0, MAX - 1);

    // Imprime os valores ordenados
    printf("Valores ordenados: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", vet[i]);
    }
    system("pause");
    return 0;
}

// Quick sort function
void quick_sort(int* a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < x && i < right) {
            i++;
        }
        while (a[j] > x&& j > left) {
            j--;
        }
        if (i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left) {
        quick_sort(a, left, j);
    }
    if (i < right) {
        quick_sort(a, i, right);
    }
}