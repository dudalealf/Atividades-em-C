/*
13.Um posto est� vendendo combust�veis com a seguinte tabela de descontos:
�lcool: at� 20 litros, desconto de 3% por litro; acima de 20 litros, desconto de 5% por litro
Gasolina: at� 20 litros, desconto de 4% por litro; acima de 20 litros, desconto de 6% por litro
Escreva um algoritmo que leia o n�mero de litros vendidos e o tipo de combust�vel (codificado da seguinte forma: 1 - �lcool, 2 - gasolina), calcule e
imprima o valor a ser pago pelo cliente sabendo-se que o pre�o do litro da gasolina � R$ 3,30 e o pre�o do litro do �lcool � R$ 2,90. */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int tipo;
	float litros, desconto, valor, alcool =2.90, gasolina =3.30;
	printf("Digite o tipo de combustivel:\n1- Alcool \n2- Gasolina\n");
	scanf("%d",&tipo);
	printf("Digite a quantidade de litros vendido: ");
	scanf("%f",&litros);
		if(tipo == 1){
			if(litros>20){
				desconto = litros*(2.90*0.05);  
				valor = (litros*alcool) - desconto;
			}
			else{
				desconto = litros*(2.90*0.03);
				valor = (litros*alcool) - desconto;
			}
		}
		else if(tipo==2){
			if(litros>20){
				desconto = litros*(3.30*0.06);  
				valor = (litros*gasolina) - desconto;
			}
			else{
				desconto = litros*(3.30*0.04);  
				valor = (litros*gasolina) - desconto;
			}
		}
			printf("Valor do desconto: R$%.2f\nO total a ser pago pelo cliente e: R$%.2f",desconto, valor);
	
	return 0;
}
