//2) Escreva um programa que receba um número inteiro qualquer e escreva na tela o seu
valor ao quadrado;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int num, quadrado;
	printf("Digite um numero inteiro: ");
	scanf("%d",&num);
	printf("\n%d ao quadrado e: %d",num, quadrado = pow(num,2));

}
