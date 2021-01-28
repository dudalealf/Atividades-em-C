//Maria Eduarda Leal Ferreira - PT3008614
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 3
void abertura(){
	printf("___________________________________________\n");
	printf("		JOGO DA VELHA\n");
	printf("___________________________________________\n");
	printf("Instru��es: 2 Jogadores. Cada jogador ir� receber seu s�mbolo (X/O) e o primeiro que formar uma linha, coluna ou diagonal com seu s�mbolo vence.\n");
	printf("\nO jogador 1 ser� X e o jogador 2 ser� O.\n\n");
	system("pause");
}
void desenhaTela(int tabuleiro[TAM][TAM]){
	system("cls");
	printf("  1      2     3\n");
	printf("1   %c |  %c  | %c  \n",tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
	printf("  _________________\n");
	printf("2   %c |  %c  | %c  \n",tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
	printf("  _________________\n");	
	printf("3   %c |  %c  | %c  \n",tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
}
int ganhou(int tabuleiro[TAM][TAM]){
	if(tabuleiro[0][0]=='X' && tabuleiro[0][1]=='X' && tabuleiro[0][2]=='X' || tabuleiro[0][0]=='O' && tabuleiro[0][1]=='O' && tabuleiro[0][2]=='O') return 1;
	if(tabuleiro[1][0]=='X' && tabuleiro[1][1]=='X' && tabuleiro[1][2]=='X' || tabuleiro[1][0]=='O' && tabuleiro[1][1]=='O' && tabuleiro[1][2]=='O') return 1;
	if(tabuleiro[2][0]=='X' && tabuleiro[2][1]=='X' && tabuleiro[2][2]=='X' || tabuleiro[2][0]=='O' && tabuleiro[2][1]=='O' && tabuleiro[2][2]=='O') return 1;
	if(tabuleiro[0][0]=='X' && tabuleiro[1][0]=='X' && tabuleiro[2][0]=='X' || tabuleiro[0][0]=='O' && tabuleiro[1][0]=='O' && tabuleiro[2][0]=='O') return 1;
	if(tabuleiro[0][1]=='X' && tabuleiro[1][1]=='X' && tabuleiro[2][1]=='X' || tabuleiro[0][1]=='O' && tabuleiro[1][1]=='O' && tabuleiro[2][1]=='O') return 1;
	if(tabuleiro[0][2]=='X' && tabuleiro[1][2]=='X' && tabuleiro[2][2]=='X' || tabuleiro[0][2]=='O' && tabuleiro[1][2]=='O' && tabuleiro[2][2]=='O') return 1;	
	if(tabuleiro[0][0]=='X' && tabuleiro[1][1]=='X' && tabuleiro[2][2]=='X' || tabuleiro[0][0]=='O' && tabuleiro[1][1]=='O' && tabuleiro[2][2]=='O') return 1;
	if(tabuleiro[2][0]=='X' && tabuleiro[1][1]=='X' && tabuleiro[0][2]=='X' || tabuleiro[2][0]=='O' && tabuleiro[1][1]=='O' && tabuleiro[0][2]=='O') return 1;
	else return 0;
} 
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	int i,j,jogadas=0,linha,coluna;
	int tabuleiro[TAM][TAM];
	abertura(); //Abertura do jogo.
	printf("\n");
	
	for(i=0;i<=2;++i){
		for(j=0;j<=2;++j){ // os for's est�o lendo cada espa�o na matriz.
			tabuleiro[i][j]=' '; //Deixando os espa�os na matriz vazios, para n�o aparecer sujeira na tela.
		}
	}
	desenhaTela(tabuleiro);
	do{
		do{
			if(jogadas%2==0) printf("\nJogador 1, digite o n�mero da linha e coluna(v�lidos), respectivamente: "); //Jogadores s�o diferenciados pelo n� de jogadas.
			else if(jogadas%2==1) printf("\nJogador 2, digite o n�mero da linha e coluna(v�lidos), respectivamente: ");
			scanf("%d%d",&linha,&coluna); 
		} while(linha<1 || linha > 3 || coluna < 1 || coluna > 3); //Enquanto for digitada uma coordenada inv�lida, o la�o ir� repetir.
	
		if(jogadas%2==0) tabuleiro[linha-1][coluna-1]='X'; //Se a jogada � par, ent�o � o jogador 1 que est� jogando, logo ser� marcado um X na coordenada, o contr�rio, � o jogador �mpar.
		else if(jogadas%2==1) tabuleiro[linha-1][coluna-1]='O'; //� subtra�do 1, pois se o usu�rio digitar coluna 1 linha 1, aqui dentro do programa esses �ndices s�o 0 e 0.
	desenhaTela(tabuleiro); //Exibe na tela o tabuleiro do jogo, com os par�metros passados pelo usu�rio.
	
		if(!ganhou(tabuleiro)) ++jogadas; //Se ningu�m ganhou ainda, ser� contabilizada uma jogada.
		if(jogadas==9 && !ganhou(tabuleiro)){
		printf("\nJOGO EMPATADO!");
		break; //Se chegou a 9 jogadas e ningu�m ganhou, o loop ser� quebrado, pois o jogo empatou.
		}	
	} while(!ganhou(tabuleiro)); //Enquanto um jogador n�o ganhar, ir� repetir.
	
	if(ganhou(tabuleiro)){
		if(jogadas%2==0) printf("\nParab�ns jogador 1!");
		else printf("\nParab�ns jogador 2!");
	}
	return 0;
}
