#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Lista {
    char nomeMusica[30];
    char nomeCantor[30];
    float duracaoMusica;
    Lista* prox;
};

Lista* inicio, * fim, * aux;

void inserirNaLista() { //fun��o que vai inserir as informa��es na lista

    int c;
    Lista* novo = (struct Lista*)malloc(sizeof(struct Lista));

    printf("Nome da m�sica?\n");
    fgets(novo->nomeMusica, 29, stdin); // recebe o nome da m�sica
    printf("Tempo de dura��o da m�sica?\n");
    scanf_s("%f", &novo->duracaoMusica);
    while ((c = getchar()) != '\n' && c != EOF) {}   // Limpar buffer do teclado
    printf("Nome do artista?\n");
    fgets(novo->nomeCantor, 29, stdin); // recebe o nome do cantor

    novo->prox = NULL;

    if (inicio == NULL) { //Insere no in�cio da lista se estiver vazia
        inicio = fim = novo;
    }
    else { //Caso n�o esteja vazia insere no pr�ximo
        fim->prox = novo;
        fim = novo;
    }
}


void mostrarLista() { //fun��o que vai mostrar as informa��es da lista

    aux = inicio;

    if (inicio == NULL) { //Informa se a lista est� vazia
        printf("Cat�logo em branco!");
    }
    else {
        while (aux != NULL) { // Caso n�o esteja passa as informa��es da lista

            printf("\n");
            printf("Nome da m�sica: %s", aux->nomeMusica);
            printf("Artista/Cantor: %s", aux->nomeCantor);
            printf("Dur���o da m�sica: %.2fs\n", aux->duracaoMusica);

            aux = aux->prox; //Passa para a pr�xima m�sica/dura��o/cantor
        }
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "");
    int opt;
    int c;

    do { // Cria um menu 
        printf("---CAT�LOGO DE M�SICAS---\n");
        printf("----------MENU----------\n");
        printf("1. catalogar uma m�sica\n");
        printf("2. Ver cat�logo\n");
        printf("3. Sair\n");
        printf("Digite sua escolha: ");
        scanf_s("%i", &opt);

        while ((c = getchar()) != '\n' && c != EOF) {}   // Limpar buffer
        switch (opt) { // Cria bot�o de op��es usando n�meros

        case 1:
            inserirNaLista(); //Ativa a fun��o que vai inserir no cat�logo
            printf("Musica inserida no cat�logo!\n");
            system("pause");
            break;

        case 2:
            mostrarLista(); //Ativa a fun��o que vai mostrar o cat�logo
            system("pause");
            break;

        case 3:
            printf("\nO programa foi encerrado com sucesso!!\n\n");
            system("pause");
            break;

        default:
            printf("\nEscolha Invalida!!\n\n");
            system("pause");
            break;

        }
        system("cls"); // Limpar a tela do cmd
    } while (opt != 3); //Cria um loop no menu
    return 0;
}
