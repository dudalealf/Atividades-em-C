/*Maria Eduarda Leal Ferreira - PT3008614
1) Escreva um programa em C para ler um valor qualquer do teclado e escrever na tela o
seu antecessor e o seu sucessor;*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int num, antecessor,sucessor;
	printf("Digite um valor: ");
	scanf("%d",&num);
	antecessor = num - 1;
	sucessor = num + 1;
	printf("\nNumero: %d \nAntecessor: %d \nSucessor: %d", num,antecessor,sucessor);
	return 0;
}
