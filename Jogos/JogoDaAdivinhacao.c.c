#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Jogo de adivinhação

O usuário precisa adivinhar um número escolhido pelo sistema. A quantidade de chutes está condicionada ao nível do jogo, também escolhido pelo usuário.

1) Gere um número inteiro aleatório. Dica: o C++ tem uma função pronta para isso => srand().
2) Pergunte para o usuário qual é o nível de dificuldade que ele quer jogar: (1) fácil; (2) médio; (3) difícil. No modo fácil, ele tem 20 chutes; no médio 15 tentativas e, no difícil, 6.
3) Pedir para o usuário fazer seu chute. Se ele não adivinhar o "número mágico", é preciso avisar se o chute está acima ou abaixo do número correto.
4) Não esquecer que essa operação precisa se repetir de acordo com a quantidade de chutes permitida para o nível escolhido anteriormente.
5) Caso o usuário adivinhe o número, exibir uma mensagem de parabéns. Caso ele não tenha acertado no final dos chutes, informar que ele perdeu e qual era, afinal, o número mágico.*/

int chutaNumero(int chute, int *numeroAleatorio, int *tentativa){
    printf("Tentativas restantes: %d", *tentativa);
    printf("\nAdivinhe o numero secreto: ");
    scanf("%d", &chute);
    if(chute == *numeroAleatorio) {
      printf("Parabens! Você adivinhou o numero secreto!\n\n");	
      return 0;
    }
    else if(chute > *numeroAleatorio){
      printf("O seu chute esta acima do numero secreto.\n\n");	
    }
    else if(chute < *numeroAleatorio){
      printf("O seu chute esta abaixo do numero correto\n\n");
    }	

    if(*tentativa == 1)     printf("\nSuas tentativas acabaram! Voce nao adivinhou o numero secreto! (%d)", *numeroAleatorio);
    return 1;
}

int main(void) {
	int dific, chute, tentativa, numeroAleatorio, reiniciar = 1;
	srand((unsigned)time(NULL));
	numeroAleatorio = rand() % 101;
	
	do{
	printf("		JOGO DE ADIVINHACAO\nSelecione o nivel da dificuldade:\n(1) facil (20 chutes)\n(2) medio (15 chutes)\n(3) dificil (6 chutes)\n");
	scanf("%d", &dific);
  printf("\n\n");
	
	switch(dific){
	case 1 :
    for (tentativa = 20; tentativa >= 1; tentativa--){
      if(chutaNumero(chute, &numeroAleatorio, &tentativa) == 0) break;
    }
    break;
	
	case 2: 
	  for (tentativa = 15; tentativa >= 1; tentativa--){
      if(chutaNumero(chute, &numeroAleatorio, &tentativa) == 0) break;
    }
	  break;
	
	case 3 : 
		for (tentativa = 6; tentativa >= 1; tentativa--){
      if(chutaNumero(chute, &numeroAleatorio, &tentativa) == 0) break;
    }
	  break;

	default :
	printf("Valor invalido");
}
	do{	
  	printf("\nDeseja jogar novamente?\n1 - Sim\n2- Não\n");
	  scanf("%d", &reiniciar);
  } while(reiniciar != 1 && reiniciar != 2);

} while(reiniciar ==1);
	return 0;
}
