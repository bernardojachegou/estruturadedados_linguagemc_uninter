#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define tempo 0.12;

int main() {
	setlocale(LC_ALL, "");

	float quantidadeMana;
	float tempoNecessario;

	printf("Quando de mana voc� pretende atingir?\n");
	scanf_s("%f", &quantidadeMana);

	tempoNecessario = quantidadeMana * tempo;
	printf("Voc� precisa de %.2f segundos\n", tempoNecessario);

	system("pause");
	return 0;
}