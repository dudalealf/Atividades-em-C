/* 
2 - Crie e teste uma função que receba um caractere como parâmetro e retorne o caractere seguinte. Considere que só serão recebidos caracteres minúsculos não acentuados. Teste.
Por exemplo:
Se receber:  Deve retornar:
    'b'             'c'
    'm'            'n'
    'z'              'a'*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
int seguinte(int letra){
	 int seguinte = letra + 1;
	 if(letra=='z'){
	 seguinte = 'a';
	 }
	return seguinte;
}
int main(int argc, char *argv[]) {
	char letra;
	setlocale(LC_ALL,"");
	printf("	LETRA SEGUINTE\nDigite uma letra: \n");
	scanf("%c",&letra); 
	printf("A letra seguinte é: %c",seguinte(letra));
	
	return 0;
}
