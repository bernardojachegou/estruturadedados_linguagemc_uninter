#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAXTAM 100

int frente;
int tras;
int fila[MAXTAM];

void fila_construtor() {
	frente = 0;
	tras = -1;
}

bool fila_vazia() {
	if (frente > tras) {
		return true;
	}
	else {
		return false;
	};
}

bool fila_cheia() {
	if (tras == MAXTAM - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool fila_criador(int valor) {
	if (fila_cheia()) {
		return false;
	}
	else {
		tras++;
		fila[tras] = valor;
		return true;
	}
}

bool fila_apagar(int &valor) {
	if (fila_vazia()) {
		return false;
	}
	else {
		valor = fila[frente];
		frente++;
		return true;
	}
}

bool fila_get(int& valor) {
	if (fila_vazia()) {
		return false;
	}
	else {
		valor = fila[frente];
		return true;
	}
}

int fila_tamanho() {
	return (tras - frente) + 1;
}

int main() {

	int valor;
	fila_construtor();

	fila_criador(4);
	fila_criador(1);
	fila_criador(7);

	if (fila_apagar(valor)) {
		printf("\n\nValor:%d\n\n", valor);
	}
	else {
		printf("\n\nFila vazia!\n\n");
	}

	system("pause");
	return 0;
}