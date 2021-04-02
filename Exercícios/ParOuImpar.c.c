/*Maria Eduarda Leal Ferreira - PT3008614 
4) Faça um programa que verifique se um número é par ou ímpar*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int num;
	printf("	IMPAR OU PAR\nDigite um numero: ");
	scanf("%d",&num);
	if(num%2 == 1){
		printf("%d e impar!", num);
	}
	else{
		printf("%d e par!", num);
	}
	return 0;
}
