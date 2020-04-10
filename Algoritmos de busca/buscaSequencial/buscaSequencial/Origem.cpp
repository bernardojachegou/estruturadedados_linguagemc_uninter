#include<stdio.h>
#include<locale.h>

int buscaSequencial(int tamanho, int vetor[], int p)
{
    int i;
    for (i = 0; i <= tamanho; i++)
    {
        if (vetor[i] == p) {
            return i;
        }
    }
    return -1;

}

int main(void) {
    setlocale(LC_ALL, "");

    int vetor_tst[8] = { 8,4,0,8,3,4,6,5 }, fun, x;
    printf("Informe o valor a ser encontrado: ");
    scanf_s("%d", &x);
    fun = buscaSequencial(8, vetor_tst, x);
    printf("posição: %d", fun);
    printf("\n\n");
    return 0;
}