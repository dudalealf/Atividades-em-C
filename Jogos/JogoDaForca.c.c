//Maria Eduarda Leal Ferreira - PT3008614
// Imports:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Constantes:
#define LVLFACIL 5
#define LVLMEDIO 7
#define LVLDIFICIL 9
#define NPALAVRAS 5

// Vari�veis globais:
char palavraChave[15];
char chutesArmazenados[26];
int chutesDados=0;
char chute;
int corretas=0;

// Prot�tipos:
void abertura();
void chutaLetra();
void computadorChuta(int qtdLetras);
void definePalavra(const int qtdLetras, char nome[]);
void desenhaForca();
void geraPalavra(const int nivel, const int qtdLetras);
void letrasDigitadas();

int acertouPalavra();
int errouChute();
int foiEnforcado();
int jaChutou(char chute);
int letraExiste(char chute);

// Fun��es:
void abertura(){
	//Abertura do jogo e instru��es.
	printf("___________________________________________   \n\n");
	printf("    	BEM-VINDO AO JOGO DA FORCA       \n\n");
	printf("___________________________________________   \n\n");
	printf("INSTRU��ES: 2 Jogadores. O jogador 1 ir� escolher uma palavra e o 2 tentar� adivinhar dando palpites em letras, s�o 6 chances, boa sorte! :)\n\n");
	printf("Observa��o: n�o devem ser utilizados acentos, algarismos ou caracteres especiais em nenhuma palavra\n\n");
}

int letraExiste(char chute){
	//Essa fun��o verifica se a letra que o jogador chutou existe na palavra chave que o jogador 1 escolheu.
	unsigned i;
	for(i = 0; i < strlen(palavraChave); ++i)
		if(chute == palavraChave[i]) return 1; //Se for igual, retorna 1.
	return 0;
}

void letrasDigitadas(){
	//Essa fun��o armazena e mostra na tela todas as letras j� digitadas pelo jogador, corretas ou erradas.
	int i;
	printf("\nLetras digitadas: ");
	for(i=0;i<chutesDados;++i)
	 printf("%c  ",chutesArmazenados[i]);
}

int jaChutou(char chute){
	/*Essa fun��o verifica se a letra digitada pelo jogador 2 j� foi digitada antes, se j� foi, ela ficar� gravada na tela,
	caso contr�rio o jogo n�o acabaria pois as letras j� digitadas ficariam "esquecidas".*/
	int j=0;
	for(j=0;j<chutesDados;j++)
		if(chutesArmazenados[j]==chute)	return 1;	
	return 0;
}

void chutaLetra(const int modo,const int escolhePalavra){	//Essa fun��o � chamada enquanto o jogador n�o perdeu ou ganhou, pedindo uma nova letra.
	int i=0,j=0;
	if(modo==1 || escolhePalavra==2){//Se a pessoa estiver jogando contra outra pessoa ou contra o computador, o sistema pede para ela chutar uma letra.
		while(jaChutou(chute) || i==0){++j; // j controla mensagem de letra j� utilizada.
		//Enquanto a pessoa repetir uma letra, o sistema pede que ela fa�a um chute v�lido.
		 /*A vari�vel i est� sendo usada para o while ser executado mesmo se for a primeira letra digitada pelo usu�rio,
		caso contr�rio o programa n�o entraria no while e seria contabilizado erro.*/
			if(j>1)printf("\nVoc� j� digitou essa letra!\n"); 
			printf("\nVamos, chute uma letra: \n"); 
			scanf("%c", &chute);
			chute= tolower(chute); //Torna a letra digitada min�scula, para seguir um padr�o.
			fflush(stdin);
			i=1; //i recebe qualquer valor, pro loop n�o continuar por conta de sua express�o.
		}		
	}
	fflush(stdin);
	j=0; //vari�vel j � zerada aqui pra mensagem de letra j� utilizada n�o ser exibida desnecessariamente.
	if(letraExiste(chute)) { //If checa se o chute existe na palavra.
		for(i=0;i<strlen(palavraChave);++i)
			if(chute == palavraChave[i] && repetiuLetra()==0) corretas++; //Acertos s� s�o contados se a pessoa acertou o chute e ele n�o � repetido.
    }
	else printf("\nVoc� errou uma letra!\n");
	chutesArmazenados[chutesDados] = chute;  //Na v�riavel chutesArmazenados ser� guardada uma c�pia de cada caractere j� digitado pelo usu�rio.
	++chutesDados;	//E a vari�vel chutesDados conta quantas vezes o usu�rio deu um chute.
}

int errouChute(){ 	//Essa fun��o, para cada chute dado pelo usu�rio, se o chute dado n�o existe na palavra chave, um erro � acrescentado.
	int erros = 0;
	unsigned i,j;
	for(i=0;i<chutesDados;++i)
		if(!letraExiste(chutesArmazenados[i]))	++erros; 
		return erros;
}

void desenhaForca(){	//Essa fun��o � a parte visual do programa, ela exibe a forca e os espa�os para a palavra secreta, erros, chances e tentativas.
	int erros = errouChute();
	system("cls");
	//Apresenta a quantidade de chutes que o usu�rio ja deu
	printf("\nQuantidade de tentativas realizadas: %d \n\n", chutesDados);
	if(erros==0){	//se o usu�rio ainda n�o errou, a forca permanecer� limpa
		printf("\n ______    \n");
		printf(" |/    |     \n");
		printf(" |           \n");
		printf(" |           \n");
		printf(" |           \n");
		printf(" |           \n");
		printf("_|__         \n\n");
	}
	//De acordo com o n�mero de chutes errados pelo jogador, a forca vai se formando.
	switch(erros){
	case 1:
	printf("\n ______    \n");
	printf(" |/    |     \n");
	printf(" |     O     \n");
	printf(" |           \n");
	printf(" |           \n");
	printf(" |           \n");
	printf("_|__         \n\n");
	break;
	case 2:
	printf("\n ______    \n");
	printf(" |/    |     \n");
	printf(" |     O     \n");
	printf(" |     |     \n");
	printf(" |     |     \n");
	printf(" |           \n");
	printf("_|__         \n\n");
	break;
	case 3:
	printf("\n ______    \n");
	printf(" |/    |     \n");
	printf(" |     O     \n");
	printf(" |    /|     \n");
	printf(" |     |     \n");
	printf(" |           \n");
	printf("_|__         \n\n");
	break;
	case 4:
	printf("\n ______    \n");
	printf(" |/    |     \n");
	printf(" |     O     \n");
	printf(" |    /|\\   \n");
	printf(" |     |     \n");
	printf(" |           \n");
	printf("_|__         \n\n");
	break;
	case 5:
	printf("\n ______    \n");
	printf(" |/    |     \n");
	printf(" |     O     \n");
	printf(" |    /|\\   \n");
	printf(" |     |     \n");
	printf(" |    /      \n");
	printf("_|__         \n\n");
	break;
	default: 
	printf("");
	break;
}
	unsigned i;
	/*As express�es a seguir checam se as letras chutadas pelo jogador existem na palavra secreta, e se j� foram digitadas pelo usu�rio,
	 se sim, � exibida a letra na tela, se n�o, ter� uma __ no lugar da letra ainda n�o encontrada.*/
	for(i = 0; i < strlen(palavraChave); ++i){
		if(jaChutou(palavraChave[i])){
		printf("%c ",palavraChave[i]);
		}
		else printf("__ ");
	}		
	printf("\n");
	letrasDigitadas();  //Mostra na tela as letras digitadas at� o momento.
	printf("\nErros: %d", erros); //Mostra quantos erros o jogador cometeu
	printf("\nCorretas: %d", corretas); //Mostra a qtd de letras corretas ate o momento.
}

//Se o jogador obteve 6 erros, essa fun��o � chamada e retorna 1 ao main, parando o loop e exibindo que o jogador perdeu.
int foiEnforcado(){ return errouChute() >= 6 ? 1 : 0; }

//Se o jogador acertou a quantidade de letras que a palavra secreta tem, ela retorna 1 ao main, interrompendo o loop e exibindo a vit�ria do jogador.
int acertouPalavra(){	return corretas == strlen(palavraChave) ? 1 : 0; }

void definePalavra(const int qtdLetras, char nome[]){
	//Essa fun��o � chamada para o jogador definir a palavra secreta.
	int confirmacao=0;
	//O loop s� para se o jogador 1 escolheu uma palavra com a qtd de caracteres do n�vel escolhido, se n�o, repete a pergunta.
	while(confirmacao==0){
		printf("\nEnt�o vamos come�ar!! %s, digite a palavra secreta: ",nome); //Palavra a ser adivinhada � definida.
		scanf("%s", &palavraChave);
		fflush(stdin);
		//Se a quantidade de letras da palavra for a ideal pro n�vel escolhido, confirmacao valer� 1 e sair� do loop.
		if(strlen(palavraChave)==qtdLetras)
		confirmacao=1;
		else{
			printf("\nA sua palavra deve ter a quantidade de caracteres do n�vel escolhido!\nF�cil= 4 letras   M�dio= 6 letras   Dif�cil= 8 letras\n");
			confirmacao = 0;
			}
		}
}

void geraPalavra(const int nivel, const int qtdLetras){
	//Fun��o que gera uma palavra aleat�ria para o jogador adivinhar.
	char palavrasFacil[NPALAVRAS][5]={"cama","bota","pato","sopa","seta"};
	char palavrasMedio[NPALAVRAS][7]={"banana","sacada","pomada","semana","ameixa"};
	char palavrasDificil[NPALAVRAS][9]={"girassol","borracha","cobertor","macarrao","biscoito"};
	srand(time(NULL));
	//vari�vel posi��o receber� um n�mero aleat�rio entre 1  e 5 (palavras dispon�veis)
	int i, posicao = rand()%5; 
	switch(nivel){
		case 1:
		/*Os la�os de repeti��o for se repetir�o at� a quantidade de letras do n�vel escolhido pelo usu�rio acabar.
		Toda vez que o la�o repetir ele passa uma letra da palavra que foi gerada aleatoriamente para a palavra secreta,
		quando acaba o la�o, a palavra secreta j� est� na vari�vel e pronta pra ser jogada. */
		for(i=0;i<=qtdLetras;++i)
		palavraChave[i]=palavrasFacil[posicao][i];
		break;
		case 2:
		for(i=0;i<=qtdLetras;++i)
		palavraChave[i]=palavrasMedio[posicao][i];
		break;
		case 3:
		for(i=0;i<=qtdLetras;++i)
		palavraChave[i]=palavrasDificil[posicao][i];
		break;
		default:
		printf("Erro inesperado.");
		break;
	}
}

void computadorChuta(int qtdLetras){	//Essa fun��o armazena um chute aleat�rio na vari�vel chute.
	char alfabeto[27]="abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	int i,posicao = rand()%26; //posicao recebe um numero aleatorio entre 1 e 26 (letras do alfabeto).
	chute= alfabeto[posicao]; //na vari�vel chute � guardada a letra que est� na posi��o da vari�vel posicao.
	for(i=0;i<strlen(chutesArmazenados);++i){
		while(jaChutou(chute)==1){ //Se o computador j� digitou aquela letra, ele escolhe outro chute.
			chute= alfabeto[rand()%26]; //e � colocada uma letra diferente.
		}	
	}
}

int main(void) {
	setlocale(LC_ALL,"PORTUGUESE");  //Fun��o que permite acentua��es no programa.
	abertura(); 	//fun��o que imprime a tela de abertura ao usu�rio
	int modo, nivel, qtdLetras, escolhePalavra=0, confirmacao=0;
	char nome2[15],nome[15];
	
	//**DADOS DOS JOGADORES E RESPECTIVOS MODOS*
	printf("Ol�, jogador 1. Digite seu nome: ");
	scanf("%s",&nome);
	fflush(stdin);
	do{ //A pergunta ser� feita novamente se o jogador digitou uma op��o inv�lida.
		printf("\nEscolha o modo do jogo: \n1- Jogador vs jogador\n2- Jogador vs computador\n");
		scanf("%d",&modo);
			if(modo==1 || modo==2) confirmacao=1;
	}while(confirmacao == 0);
	do{
		printf("\nEscolha o n�vel de dificuldade:\n1-F�cil(4 letras)\n2-M�dio(6 letras)\n3-Dif�cil(8 letras)\n");
		scanf("%d",&nivel);
		//O Switch ir� definir a quantidade de letras m�ximas para o n�vel escolhido pelo usu�rio.
		switch(nivel){
			case 1:
				qtdLetras=4;
			break;
			case 2:
				qtdLetras=6;
			break;
			case 3:
				qtdLetras=8;
			break;
			default:
				printf("\nOp��o inv�lida!\n");
				confirmacao=0;
				
			break;
		}
	} while(confirmacao==0);
	//If's ir�o definir como ser� a din�mica do jogo de acordo com a op��o do jogador.
	if(modo==1) {
		printf("Jogador 2, digite seu nome: ");
		scanf("%s", &nome2);
		fflush(stdin);
		definePalavra(qtdLetras,nome);
	}else
	if(modo==2){
		printf("1\n1- Jogador escolhe a palavra ou 2- Computador escolhe a palavra. \n");
		scanf("%d",&escolhePalavra);
		fflush(stdin);
			if(escolhePalavra==2){
				fflush(stdin);
				//Caso o jogador queira que o computador escolha a palavra, essa fun��o ir� gerar uma palavra aleat�ria.
				geraPalavra(nivel,qtdLetras);
		}
	}
	//**FIM DOS DADOS DOS JOGADORES**
	system("cls");
	/*O la�o do-while, utilizado em dois momento a seguir, define que enquanto o jogador n�o acertar a palavra ou n�o ser enforcado,
	 o programa continuar� pedindo letras e desenhando a forca*/
	if(escolhePalavra==2 || modo==1){ //se o modo que a pessoa escolheu n�o � o "Jogador escolhe a palavra pro computador", essas fun��es ser�o chamadas:
		do{
			desenhaForca();
			chutaLetra(modo,escolhePalavra);
		}while(!acertouPalavra() && !foiEnforcado());
	}
	else if(escolhePalavra==1){ //Se a pessoa escolheu o modo "Jogador escolhe a palavra pro computador", essas fun��es ser�o chamadas:
		printf("\nVoc� escolheu jogar contra mim! Vamos l�\n"); 
		definePalavra(qtdLetras,nome);
		do{
			computadorChuta(qtdLetras);
			desenhaForca();
			printf("\nAPERTE QUALQUER LETRA PARA VER MEU PR�XIMO CHUTE..\n");
			system("pause");
			chutaLetra(modo,escolhePalavra);
		}while(!acertouPalavra() && !foiEnforcado());	
	}
	system("cls");
	//Se o jogador errou 6 letras, a mensagem de erro aparecer� na tela: 
	if(foiEnforcado()){
		if(escolhePalavra==1){ //Se o computador perdeu, ser� exibida uma mensagem alternativa de derrota.
			printf("\n                 G   A   M   E   O   V   E   R\n\nESSA N�O! EU PERDI.... /(�.�)\\ \nAh... A palavra era %s\n",palavraChave);
		}
		else{
		printf("\n ______                      \n");
		printf(" |/    |          ______       \n");
		printf(" |     #         /      \\    \n");
		printf(" |    /|\\       |   +    |    \n");
		printf(" |     |        |  RIP   |     \n");
		printf(" |    / \\       |        |    \n");
		printf("_|__            |        |      \n");
		printf("\n\n		G   A   M   E   O   V   E   R\n\nEssa n�o, voc� perdeu!!! Mas n�o fique triste! Tente novamente :)");
		printf("\n\nA palavra era: %s", palavraChave);
		}
	} else{ //Se o jogador adivinhou a palavra, a mensagem de vit�ria aparecer� na tela:
		if(escolhePalavra==1){ //Se o computador ganhou, ser� exibida uma mensagem alternativa de vit�ria.
			printf("\nEU GANHEIIIIIIIIIIIII!!! \\(�u�)/\nA palavra era: %s\n",palavraChave);
		} else
	printf("\n ______             \n");
	printf(" |/    |              \n");
	printf(" |                    \n");
	printf(" |    \\ O /          \n");
	printf(" |      |             \n");
	printf(" |      |             \n");
	printf("_|__   / \\           \n");
	printf("\n\n        P   A   R   A   B   �   N   S!!!!\n\nVoc� acertou a palavra!! Palavra escolhida: %s\n",palavraChave);
	}
	
	return 0;
}
