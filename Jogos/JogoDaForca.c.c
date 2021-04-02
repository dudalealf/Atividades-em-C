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

// Variáveis globais:
char palavraChave[15];
char chutesArmazenados[26];
int chutesDados=0;
char chute;
int corretas=0;

// Protótipos:
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

// Funções:
void abertura(){
	//Abertura do jogo e instruções.
	printf("___________________________________________   \n\n");
	printf("    	BEM-VINDO AO JOGO DA FORCA       \n\n");
	printf("___________________________________________   \n\n");
	printf("INSTRUÇÕES: 2 Jogadores. O jogador 1 irá escolher uma palavra e o 2 tentará adivinhar dando palpites em letras, são 6 chances, boa sorte! :)\n\n");
	printf("Observação: não devem ser utilizados acentos, algarismos ou caracteres especiais em nenhuma palavra\n\n");
}

int letraExiste(char chute){
	//Essa função verifica se a letra que o jogador chutou existe na palavra chave que o jogador 1 escolheu.
	unsigned i;
	for(i = 0; i < strlen(palavraChave); ++i)
		if(chute == palavraChave[i]) return 1; //Se for igual, retorna 1.
	return 0;
}

void letrasDigitadas(){
	//Essa função armazena e mostra na tela todas as letras já digitadas pelo jogador, corretas ou erradas.
	int i;
	printf("\nLetras digitadas: ");
	for(i=0;i<chutesDados;++i)
	 printf("%c  ",chutesArmazenados[i]);
}

int jaChutou(char chute){
	/*Essa função verifica se a letra digitada pelo jogador 2 já foi digitada antes, se já foi, ela ficará gravada na tela,
	caso contrário o jogo não acabaria pois as letras já digitadas ficariam "esquecidas".*/
	int j=0;
	for(j=0;j<chutesDados;j++)
		if(chutesArmazenados[j]==chute)	return 1;	
	return 0;
}

void chutaLetra(const int modo,const int escolhePalavra){	//Essa função é chamada enquanto o jogador não perdeu ou ganhou, pedindo uma nova letra.
	int i=0,j=0;
	if(modo==1 || escolhePalavra==2){//Se a pessoa estiver jogando contra outra pessoa ou contra o computador, o sistema pede para ela chutar uma letra.
		while(jaChutou(chute) || i==0){++j; // j controla mensagem de letra já utilizada.
		//Enquanto a pessoa repetir uma letra, o sistema pede que ela faça um chute válido.
		 /*A variável i está sendo usada para o while ser executado mesmo se for a primeira letra digitada pelo usuário,
		caso contrário o programa não entraria no while e seria contabilizado erro.*/
			if(j>1)printf("\nVocê já digitou essa letra!\n"); 
			printf("\nVamos, chute uma letra: \n"); 
			scanf("%c", &chute);
			chute= tolower(chute); //Torna a letra digitada minúscula, para seguir um padrão.
			fflush(stdin);
			i=1; //i recebe qualquer valor, pro loop não continuar por conta de sua expressão.
		}		
	}
	fflush(stdin);
	j=0; //variável j é zerada aqui pra mensagem de letra já utilizada não ser exibida desnecessariamente.
	if(letraExiste(chute)) { //If checa se o chute existe na palavra.
		for(i=0;i<strlen(palavraChave);++i)
			if(chute == palavraChave[i] && repetiuLetra()==0) corretas++; //Acertos só são contados se a pessoa acertou o chute e ele não é repetido.
    }
	else printf("\nVocê errou uma letra!\n");
	chutesArmazenados[chutesDados] = chute;  //Na váriavel chutesArmazenados será guardada uma cópia de cada caractere já digitado pelo usuário.
	++chutesDados;	//E a variável chutesDados conta quantas vezes o usuário deu um chute.
}

int errouChute(){ 	//Essa função, para cada chute dado pelo usuário, se o chute dado não existe na palavra chave, um erro é acrescentado.
	int erros = 0;
	unsigned i,j;
	for(i=0;i<chutesDados;++i)
		if(!letraExiste(chutesArmazenados[i]))	++erros; 
		return erros;
}

void desenhaForca(){	//Essa função é a parte visual do programa, ela exibe a forca e os espaços para a palavra secreta, erros, chances e tentativas.
	int erros = errouChute();
	system("cls");
	//Apresenta a quantidade de chutes que o usuário ja deu
	printf("\nQuantidade de tentativas realizadas: %d \n\n", chutesDados);
	if(erros==0){	//se o usuário ainda não errou, a forca permanecerá limpa
		printf("\n ______    \n");
		printf(" |/    |     \n");
		printf(" |           \n");
		printf(" |           \n");
		printf(" |           \n");
		printf(" |           \n");
		printf("_|__         \n\n");
	}
	//De acordo com o número de chutes errados pelo jogador, a forca vai se formando.
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
	/*As expressões a seguir checam se as letras chutadas pelo jogador existem na palavra secreta, e se já foram digitadas pelo usuário,
	 se sim, é exibida a letra na tela, se não, terá uma __ no lugar da letra ainda não encontrada.*/
	for(i = 0; i < strlen(palavraChave); ++i){
		if(jaChutou(palavraChave[i])){
		printf("%c ",palavraChave[i]);
		}
		else printf("__ ");
	}		
	printf("\n");
	letrasDigitadas();  //Mostra na tela as letras digitadas até o momento.
	printf("\nErros: %d", erros); //Mostra quantos erros o jogador cometeu
	printf("\nCorretas: %d", corretas); //Mostra a qtd de letras corretas ate o momento.
}

//Se o jogador obteve 6 erros, essa função é chamada e retorna 1 ao main, parando o loop e exibindo que o jogador perdeu.
int foiEnforcado(){ return errouChute() >= 6 ? 1 : 0; }

//Se o jogador acertou a quantidade de letras que a palavra secreta tem, ela retorna 1 ao main, interrompendo o loop e exibindo a vitória do jogador.
int acertouPalavra(){	return corretas == strlen(palavraChave) ? 1 : 0; }

void definePalavra(const int qtdLetras, char nome[]){
	//Essa função é chamada para o jogador definir a palavra secreta.
	int confirmacao=0;
	//O loop só para se o jogador 1 escolheu uma palavra com a qtd de caracteres do nível escolhido, se não, repete a pergunta.
	while(confirmacao==0){
		printf("\nEntão vamos começar!! %s, digite a palavra secreta: ",nome); //Palavra a ser adivinhada é definida.
		scanf("%s", &palavraChave);
		fflush(stdin);
		//Se a quantidade de letras da palavra for a ideal pro nível escolhido, confirmacao valerá 1 e sairá do loop.
		if(strlen(palavraChave)==qtdLetras)
		confirmacao=1;
		else{
			printf("\nA sua palavra deve ter a quantidade de caracteres do nível escolhido!\nFácil= 4 letras   Médio= 6 letras   Difícil= 8 letras\n");
			confirmacao = 0;
			}
		}
}

void geraPalavra(const int nivel, const int qtdLetras){
	//Função que gera uma palavra aleatória para o jogador adivinhar.
	char palavrasFacil[NPALAVRAS][5]={"cama","bota","pato","sopa","seta"};
	char palavrasMedio[NPALAVRAS][7]={"banana","sacada","pomada","semana","ameixa"};
	char palavrasDificil[NPALAVRAS][9]={"girassol","borracha","cobertor","macarrao","biscoito"};
	srand(time(NULL));
	//variável posição receberá um número aleatório entre 1  e 5 (palavras disponíveis)
	int i, posicao = rand()%5; 
	switch(nivel){
		case 1:
		/*Os laços de repetição for se repetirão até a quantidade de letras do nível escolhido pelo usuário acabar.
		Toda vez que o laço repetir ele passa uma letra da palavra que foi gerada aleatoriamente para a palavra secreta,
		quando acaba o laço, a palavra secreta já está na variável e pronta pra ser jogada. */
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

void computadorChuta(int qtdLetras){	//Essa função armazena um chute aleatório na variável chute.
	char alfabeto[27]="abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	int i,posicao = rand()%26; //posicao recebe um numero aleatorio entre 1 e 26 (letras do alfabeto).
	chute= alfabeto[posicao]; //na variável chute é guardada a letra que está na posição da variável posicao.
	for(i=0;i<strlen(chutesArmazenados);++i){
		while(jaChutou(chute)==1){ //Se o computador já digitou aquela letra, ele escolhe outro chute.
			chute= alfabeto[rand()%26]; //e é colocada uma letra diferente.
		}	
	}
}

int main(void) {
	setlocale(LC_ALL,"PORTUGUESE");  //Função que permite acentuações no programa.
	abertura(); 	//função que imprime a tela de abertura ao usuário
	int modo, nivel, qtdLetras, escolhePalavra=0, confirmacao=0;
	char nome2[15],nome[15];
	
	//**DADOS DOS JOGADORES E RESPECTIVOS MODOS*
	printf("Olá, jogador 1. Digite seu nome: ");
	scanf("%s",&nome);
	fflush(stdin);
	do{ //A pergunta será feita novamente se o jogador digitou uma opção inválida.
		printf("\nEscolha o modo do jogo: \n1- Jogador vs jogador\n2- Jogador vs computador\n");
		scanf("%d",&modo);
			if(modo==1 || modo==2) confirmacao=1;
	}while(confirmacao == 0);
	do{
		printf("\nEscolha o nível de dificuldade:\n1-Fácil(4 letras)\n2-Médio(6 letras)\n3-Difícil(8 letras)\n");
		scanf("%d",&nivel);
		//O Switch irá definir a quantidade de letras máximas para o nível escolhido pelo usuário.
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
				printf("\nOpção inválida!\n");
				confirmacao=0;
				
			break;
		}
	} while(confirmacao==0);
	//If's irão definir como será a dinâmica do jogo de acordo com a opção do jogador.
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
				//Caso o jogador queira que o computador escolha a palavra, essa função irá gerar uma palavra aleatória.
				geraPalavra(nivel,qtdLetras);
		}
	}
	//**FIM DOS DADOS DOS JOGADORES**
	system("cls");
	/*O laço do-while, utilizado em dois momento a seguir, define que enquanto o jogador não acertar a palavra ou não ser enforcado,
	 o programa continuará pedindo letras e desenhando a forca*/
	if(escolhePalavra==2 || modo==1){ //se o modo que a pessoa escolheu não é o "Jogador escolhe a palavra pro computador", essas funções serão chamadas:
		do{
			desenhaForca();
			chutaLetra(modo,escolhePalavra);
		}while(!acertouPalavra() && !foiEnforcado());
	}
	else if(escolhePalavra==1){ //Se a pessoa escolheu o modo "Jogador escolhe a palavra pro computador", essas funções serão chamadas:
		printf("\nVocê escolheu jogar contra mim! Vamos lá\n"); 
		definePalavra(qtdLetras,nome);
		do{
			computadorChuta(qtdLetras);
			desenhaForca();
			printf("\nAPERTE QUALQUER LETRA PARA VER MEU PRÓXIMO CHUTE..\n");
			system("pause");
			chutaLetra(modo,escolhePalavra);
		}while(!acertouPalavra() && !foiEnforcado());	
	}
	system("cls");
	//Se o jogador errou 6 letras, a mensagem de erro aparecerá na tela: 
	if(foiEnforcado()){
		if(escolhePalavra==1){ //Se o computador perdeu, será exibida uma mensagem alternativa de derrota.
			printf("\n                 G   A   M   E   O   V   E   R\n\nESSA NÃO! EU PERDI.... /(º.º)\\ \nAh... A palavra era %s\n",palavraChave);
		}
		else{
		printf("\n ______                      \n");
		printf(" |/    |          ______       \n");
		printf(" |     #         /      \\    \n");
		printf(" |    /|\\       |   +    |    \n");
		printf(" |     |        |  RIP   |     \n");
		printf(" |    / \\       |        |    \n");
		printf("_|__            |        |      \n");
		printf("\n\n		G   A   M   E   O   V   E   R\n\nEssa não, você perdeu!!! Mas não fique triste! Tente novamente :)");
		printf("\n\nA palavra era: %s", palavraChave);
		}
	} else{ //Se o jogador adivinhou a palavra, a mensagem de vitória aparecerá na tela:
		if(escolhePalavra==1){ //Se o computador ganhou, será exibida uma mensagem alternativa de vitória.
			printf("\nEU GANHEIIIIIIIIIIIII!!! \\(ºuº)/\nA palavra era: %s\n",palavraChave);
		} else
	printf("\n ______             \n");
	printf(" |/    |              \n");
	printf(" |                    \n");
	printf(" |    \\ O /          \n");
	printf(" |      |             \n");
	printf(" |      |             \n");
	printf("_|__   / \\           \n");
	printf("\n\n        P   A   R   A   B   É   N   S!!!!\n\nVocê acertou a palavra!! Palavra escolhida: %s\n",palavraChave);
	}
	
	return 0;
}
