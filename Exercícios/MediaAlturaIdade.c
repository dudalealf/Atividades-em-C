/*Maria Eduarda Leal Ferreira - PT3008614
7. Para uma turma de 45 alunos, construa um algoritmo que determine:
a) A idade média dos alunos com menos de 1,70m de altura; b) A altura média dos alunos com mais de 20 anos.*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	float media,altura,alturaMed=0,alturaAcum=0;
	int idade,idadeMed=0,idadeAcum=0,contAltura=0,contIdade=0,alunos=45;
	do{ 
	printf("\nDigite sua idade: ");
	scanf("%d",&idade);
	printf("Digite sua altura: ");
	scanf("%f",&altura);
		if(altura<1.70){
			idadeAcum = idadeAcum + idade;
			contAltura = contAltura + 1;
		}
		if(idade>20){
			alturaAcum = alturaAcum + altura;
			contIdade = contIdade + 1;
		}
	alunos = alunos -1;
	} while(alunos>0);
	
	idadeMed = idadeAcum/contAltura;
	alturaMed = alturaAcum/contIdade;
	printf("A idade media dos alunos com menos de 1.70 e: %d",idadeMed);
	printf("\nA altura media dos alunos com mais de 20 anos e: %.2f",alturaMed);
	return 0;
}

