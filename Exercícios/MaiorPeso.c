//3. (OBRIGATÓRIO) Crie um algoritmo que leia a altura e o peso de 6 pessoas e apresente a altura da pessoa mais pesada.
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	double altura, peso,maiorPeso,novaAltura,cont = 1;
	int pessoa=0;
	maiorPeso = peso;
	do{
		printf("Informe sua altura: ");
		scanf("%lf",&altura);
		printf("Informe seu peso: ");
		scanf("%lf",&peso);
		printf("Altura: %.2lf   Peso: %.2lf\n\n",altura,peso);
		cont = cont + 1;
			if(peso > maiorPeso){
			maiorPeso=peso;
			novaAltura=altura;
		}
	} while(cont<=6);
	
	printf("A altura da pessoa mais pesada e: %.2lf",novaAltura);
	
	return 0;
}
