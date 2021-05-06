/*Maria Eduarda Leal Ferreira - PT3008614
12.Ler o salário fixo e o valor das vendas efetuadas pelo vendedor de uma empresa. Sabendo-se que ele recebe uma comissão de 3% sobre o total das
vendas até R$ 1.500,00 mais 5% sobre o que ultrapassar este valor, calcular e escrever o seu salário total.  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	double salario,vendas,salTotal;
	printf("Digite o salario fixo: ");
	scanf("%lf",&salario);
	printf("Digite o valor das vendas: ");
	scanf("%lf",&vendas);
		if(vendas > 1500){
		salTotal = (vendas*0.05) + salario;
		printf("O salario total desse vendedor e de: %.2lf", salTotal);
		}
		else {
			salTotal = (vendas*0.03) + salario;
			printf("O salario total desse vendedor e de: %.2lf", salTotal);
		}
return 0;
}
