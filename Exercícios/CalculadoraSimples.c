
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
int main(int argc, char *argv[]) {
	int op,repetir=1,cont;
	double n1,n2,raio,area;
	while(repetir==1){
	printf("	CALCULADORA\nDigite a operacao que deseja\n1- soma(+)\n2- subtracao(-)\n3- multiplicacao(*)\n4- divisao(/)\n5- area do circulo\n0- sair\n");
	scanf("%d",&op);
 	if(op==1 || op==2 || op==3 || op==4){
	printf("Digite o primeiro numero: \n");
	scanf("%lf",&n1);
	printf("\nDigite o segundo numero: \n");
	scanf("%lf",&n2);
	}	
	
	switch(op){
		case 1:
			printf("%.2lf + %.2lf = %.2lf",n1,n2,n1+n2);
		break;
		case 2:
			printf("%.2lf - %.2lf = %.2lf",n1,n2,n1-n2);
		break;
		case 3:
			for(cont=0;cont<n2;cont++){
				printf(" %.2lf +",n1);
			}
			n1*=n2;
			printf("= %.2lf", n1);
		break;
		case 4: 
		if(n2!=0){
			printf("%.2lf / %.2lf = %.2lf",n1,n2,n1/n2);
		} else
			printf("\nImpossivel dividir por 0!");
		break;
		case 5: 
			printf("	AREA DO CIRCULO\nDigite o raio do circulo: ");
			scanf("%lf",&raio);
			area=PI*(pow(raio,2));
			printf("\nArea: %.2lf",area);
		break;
		case 0: 
		break;
		default: 
			printf("Digite uma opcao valida!");
		break;
		}
		printf("\nDeseja efetuar nova operacao?\n1- Sim\n2- Nao\n");
		scanf("%d",&repetir);
	}

	return 0;
}

