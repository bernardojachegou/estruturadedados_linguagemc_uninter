#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct {
    char nome[200];
    char email[30];
    int ru;
} Aluno;

Aluno aluno_uninter[10];
char nome[200];
int posicao;

int main() {
    setlocale(LC_ALL, "");
    int i = 0;

    for (i = 0; i < 5; i++) {
        aluno_uninter[i].ru = 0;
        strcpy_s(aluno_uninter[i].nome, "NULL");
        strcpy_s(aluno_uninter[i].email, "NULL");
    }

    for (i = 0; i < 5; i++) {
        printf(" \n O ru do aluno especial é: %d ", aluno_uninter[i].ru);
        printf(" \n O nome do aluno especial é: %s ", aluno_uninter[i].nome);
        printf(" \n A email do aluno especial é: %s ", aluno_uninter[i].email);
        printf(" \n ------------------------------------------------------------------------");
    }

    printf(" \n \n");

    for (i = 0; i < 5; i++) {
        printf(" Digite o ru do aluno especial: ");
        scanf_s("%d%*c", &aluno_uninter[i].ru);
        printf(" Digite o nome do aluno: ");
        gets_s(aluno_uninter[i].nome);
        printf(" Digite o e-mail do aluno: ");
        gets_s(aluno_uninter[i].email);
        printf(" \n ------------------------------------------------------------------------\n");
    }

    for (i = 0; i < 5; i++) {
        printf(" \n O código do aluno especial é: %d ", aluno_uninter[i].ru);
        printf(" \n O nome do aluno especial é: %s ", aluno_uninter[i].nome);
        printf(" \n A nota do aluno especial é: %s ", aluno_uninter[i].email);
        printf(" \n ------------------------------------------------------------------------");
    }

    printf(" \n ");

    printf(" \n Digite um nome: ");
    gets_s(nome);

    for (i = 0; i < 5; i++) {
        if (strcmp(nome, aluno_uninter[i].nome) == 0) {
            printf("\n Registro encontrado! ");
            posicao = i;
        }
        else {
            posicao = -1;
        }
    }

    if (posicao == -1) {
        printf(" \n Registro não encontrado! ");
    }
    else {
        printf(" \n Nome Encontrado");
        printf(" \n Nome é: %s", nome);
        printf(" \n O código do aluno especial é: %d ", aluno_uninter[posicao].ru);
        printf(" \n O nome do aluno especial é: %s ", aluno_uninter[posicao].nome);
        printf(" \n A nota do aluno especial é: %s ", aluno_uninter[posicao].email);
        printf(" \n ------------------------------------------------------------------------");
    }

    for (i = 0; i < 5; i++) {
        if ((aluno_uninter[i].ru >= 4) & (aluno_uninter[i].ru <= 7)) {
            printf(" \n O código do aluno especial é: %d ", aluno_uninter[i].ru);
            printf(" \n O nome do aluno especial é: %s ", aluno_uninter[i].nome);
            printf(" \n A nota do aluno especial é: %s ", aluno_uninter[i].email);
            printf(" \n ------------------------------------------------------------------------");
        }
        else {
            posicao = -1;
        }
    }

    if (posicao == -1) {
        printf("\n Não há registros com esta configuração!");
    }

    return 0;

}