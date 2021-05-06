#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Jogo de adivinha��o

O usu�rio precisa adivinhar um n�mero escolhido pelo sistema. A quantidade de chutes est� condicionada ao n�vel do jogo, tamb�m escolhido pelo usu�rio.

1) Gere um n�mero inteiro aleat�rio. Dica: o C++ tem uma fun��o pronta para isso => srand().
2) Pergunte para o usu�rio qual � o n�vel de dificuldade que ele quer jogar: (1) f�cil; (2) m�dio; (3) dif�cil. No modo f�cil, ele tem 20 chutes; no m�dio 15 tentativas e, no dif�cil, 6.
3) Pedir para o usu�rio fazer seu chute. Se ele n�o adivinhar o "n�mero m�gico", � preciso avisar se o chute est� acima ou abaixo do n�mero correto.
4) N�o esquecer que essa opera��o precisa se repetir de acordo com a quantidade de chutes permitida para o n�vel escolhido anteriormente.
5) Caso o usu�rio adivinhe o n�mero, exibir uma mensagem de parab�ns. Caso ele n�o tenha acertado no final dos chutes, informar que ele perdeu e qual era, afinal, o n�mero m�gico.*/

int chutaNumero(int chute, int *numeroAleatorio, int *tentativa){
    printf("Tentativas restantes: %d", *tentativa);
    printf("\nAdivinhe o numero secreto: ");
    scanf("%d", &chute);
    if(chute == *numeroAleatorio) {
      printf("Parabens! Voc� adivinhou o numero secreto!\n\n");	
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
  	printf("\nDeseja jogar novamente?\n1 - Sim\n2- N�o\n");
	  scanf("%d", &reiniciar);
  } while(reiniciar != 1 && reiniciar != 2);

} while(reiniciar ==1);
	return 0;
}
