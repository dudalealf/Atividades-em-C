/*Maria Eduarda Leal Ferreira - PT3008614
3) Faça um programa que calcule a área de um retângulo com dimensões x e y fornecidas
pelo usuário; */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	float area,altura,base;
	printf("	AREA DO RETANGULO\nDigite a base: ");
	scanf("%f",&base);
	printf("\nDigite a altura: ");
	scanf("%f",&altura);
	area= base*altura;
	printf("\nBase: %.2f\nAltura: %.2f\nArea: %.2f",base,altura,area);
	return 0;
}
