
#include <stdio.h>
#include <stdlib.h>
#define TAM 15
/*Encontre o menor e maior valor de um vetor de inteiros de 15 posições*/
int main(int argc, char *argv[]) {
	int str[TAM]={1,54,7,18,233,12,45,48,90,500,2,32,81,125,222};
	int maior=str[0];
	int menor=str[0];
	int i;
	for(i=0;i<TAM;++i){
		if(str[i]>maior){
			maior = str[i];
		}
		if(str[i]< menor){
			menor = str[i];
		}
	}
	printf("Maior valor do vetor: %d\nMenor valor do vetor: %d",maior,menor);
	
	return 0;
}
