/* (OBRIGAT�RIO) Foi feita uma pesquisa entre os habitantes de uma regi�o. Foram coletados os dados de idade, sexo (M/F) e sal�rio. Fa�a um algoritmo que informe:
a) a m�dia salarial do grupo; b) a maior e a menor idade do grupo; c) a quantidade de mulheres com sal�rio at� R$1000,00
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int idade,cont=0,mulheres=0,maiorIdade,menorIdade;
	char sexo;
	double salario,medSalario=0,media;
	
	printf("\nDigite a idade (Escreva uma idade negativa para parar): ");
	scanf("%d",&idade);
		if(idade>0){
		maiorIdade = idade;
		menorIdade = idade;
	}
	do{
	printf("Digite o sexo (M para masculino, F para feminino): ");
	fflush(stdin);
	scanf("%s",&sexo);
		if(sexo=='f' && salario<=1000.00){
		mulheres = mulheres + 1;
		}
	printf("Digite o salario: ");
	scanf("%lf",&salario);
	medSalario = medSalario + salario;
	cont = cont + 1;
	printf("\nDigite a idade: (Digite uma idade negativa para parar)");
	scanf("%d",&idade);
		if(idade>maiorIdade){
		maiorIdade = idade;
		} else
		if(idade<menorIdade && idade>0){
		menorIdade = idade;
		}
	} while (idade>0);
	media = medSalario/cont;
	printf("Media salarial do grupo: %.2lf",media);
	printf("\nMaior idade do grupo: %d\nMenor idade do grupo: %d",maiorIdade,menorIdade);
	printf("\nQuantidade de mulheres com salario ate R$1000.00: %d",mulheres);
	return 0;
}

