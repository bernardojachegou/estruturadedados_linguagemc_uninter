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

void inserirNaLista() { //função que vai inserir as informações na lista

    int c;
    Lista* novo = (struct Lista*)malloc(sizeof(struct Lista));

    printf("Nome da música?\n");
    fgets(novo->nomeMusica, 29, stdin); // recebe o nome da música
    printf("Tempo de duração da música?\n");
    scanf_s("%f", &novo->duracaoMusica);
    while ((c = getchar()) != '\n' && c != EOF) {}   // Limpar buffer do teclado
    printf("Nome do artista?\n");
    fgets(novo->nomeCantor, 29, stdin); // recebe o nome do cantor

    novo->prox = NULL;

    if (inicio == NULL) { //Insere no início da lista se estiver vazia
        inicio = fim = novo;
    }
    else { //Caso não esteja vazia insere no próximo
        fim->prox = novo;
        fim = novo;
    }
}


void mostrarLista() { //função que vai mostrar as informações da lista

    aux = inicio;

    if (inicio == NULL) { //Informa se a lista está vazia
        printf("Catálogo em branco!");
    }
    else {
        while (aux != NULL) { // Caso não esteja passa as informações da lista

            printf("\n");
            printf("Nome da música: %s", aux->nomeMusica);
            printf("Artista/Cantor: %s", aux->nomeCantor);
            printf("Durãção da música: %.2fs\n", aux->duracaoMusica);

            aux = aux->prox; //Passa para a próxima música/duração/cantor
        }
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "");
    int opt;
    int c;

    do { // Cria um menu 
        printf("---CATÁLOGO DE MÚSICAS---\n");
        printf("----------MENU----------\n");
        printf("1. catalogar uma música\n");
        printf("2. Ver catálogo\n");
        printf("3. Sair\n");
        printf("Digite sua escolha: ");
        scanf_s("%i", &opt);

        while ((c = getchar()) != '\n' && c != EOF) {}   // Limpar buffer
        switch (opt) { // Cria botão de opções usando números

        case 1:
            inserirNaLista(); //Ativa a função que vai inserir no catálogo
            printf("Musica inserida no catálogo!\n");
            system("pause");
            break;

        case 2:
            mostrarLista(); //Ativa a função que vai mostrar o catálogo
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
