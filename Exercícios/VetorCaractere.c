#include <iostream>
#include <stdio.h>
/*• Declare um vetor de caracteres e inicialize com a string "algoritmos".
Então conte quantos caracteres tem esta string e imprima. */
int main(int argc, char** argv) {
	char str[]= "algoritmos"; 
	int i;
	for(i=0;str[i];++i){
		printf("Caractere: %c\n",str[i]);
	}
	printf("Quantidade de caracteres: %d\n", i);
	printf("Tamanho da string: %d",sizeof(str));
	return 0;
}
