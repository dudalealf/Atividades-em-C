
//2. Faça um algoritmo que calcule e imprima o fatorial de um número inteiro.*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int total,num,fator=1;
	
	printf("	FATORIAL DE UM NUMERO\nDigite um numero: ");
	scanf("%d",&num);
	int numero= num;
	if(num==0){
		fator = 1;
	}
	else{
		do{
			fator= fator * num;
		//	printf("\nnumero: %d   fatorial: %d\n",num,fator);
			num = num - 1;
		} while(num > 1); 
	}
	printf("A fatorial de %d e igual a: %d",numero,fator);
	return 0;
}
