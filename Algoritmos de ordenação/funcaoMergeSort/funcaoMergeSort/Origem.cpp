#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void intercalar(int v[], int aux[], int ini1, int ini2, int fim2);
void mergeSort(int v[], int aux[], int esq, int dir);

int main()
{
    int v[10] = { 45,23,10,25,89,75,46,32,20,1 }, aux[10], i;
    
    mergeSort(v, aux, 0, 9);

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", v[i]);
    }
    system("pause");
    return 0;
}

void intercalar(int v[], int aux[], int ini1, int ini2, int fim2) {
    int inicio1 = ini1;
    int inicio2 = ini2; 
    int fim1 = inicio2 - 1;
    int au = 0;
    int i;

    while (inicio1 <= fim1 && inicio2 <= fim2)
    {
        if (v[inicio1] < v[inicio2])
        {
            aux[au++] = v[inicio1++];
        }
        else
        {
            aux[au++] = v[inicio2++];
        }
    }
    while (inicio1 <= fim1)
    {
        aux[au++] = v[inicio1++];
    }
    while (inicio2 <= fim2)
    {
        aux[au++] = v[inicio2++];
    }

    for (i = 0; i < au; i++) {
        v[i + ini1] = aux[i];
    }
}

//função merge
void mergeSort(int v[], int aux[], int esq, int dir)
{
    int meio;
    int i;
    if (esq < dir)
    {
        meio = (esq + dir) / 2;
        mergeSort(v, aux, esq, meio);
        mergeSort(v, aux, meio + 1, dir);
        intercalar(v, aux, esq, meio + 1, dir);
    }
}