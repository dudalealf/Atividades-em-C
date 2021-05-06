/*
8. Tendo como entrada a altura e o sexo (codificado o sexo através do número 1
para feminino e 2 para masculino) de uma pessoa, construa um programa que calcule e imprima seu peso ideal, utilizando as seguintes Fórmulas:
a. Para homens: (72.7 * Altura) – 58 / b. Para mulheres: (62.1 * Altura) – 44.7 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	double altura,ideal;
	int sexo;
	printf("		PESO IDEAL\nDigite a sua altura: (ex: 1.66) ");
	scanf("%lf",&altura);
	printf("\nDigite seu sexo:\n1- Feminino \n2- Masculino\n");
	scanf("%d",&sexo);
		if(sexo == 1){
			ideal = (62.1 * altura) - 44.7;
			printf("Seu peso ideal e: %.1lf ",ideal);
		}
		else{
			ideal = (72.7 * altura) - 58;
			printf("Seu peso ideal e: %.1lf ",ideal);
		}
	return 0;
}
