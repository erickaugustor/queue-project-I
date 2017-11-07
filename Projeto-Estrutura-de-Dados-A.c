	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <windows.h>

	#include <conio.h>
	#include <math.h>
	#include "tela.h"

	#define CLOCKS_PER_SEC 2500000000

	//ESTRUTURAS
	typedef struct tno{
    	int chave;
    	time_t entrada, saida;
    	struct tno *prox;
	} no;

	//SPIN
	char spin() {
	static int indice=-1;
	char spin[] = {'-', '\\', '|', '/'};

	indice = ++indice % 4;
    return spin[indice];
	}
	
	//LEITURA
	char leitura() {				// Leitura de 1 caracter nao-bloqueante
		if (kbhit()) {				// retorna true se alguma tecla foi pressionada
			return getch();
		}
		return '\0';
	}

	//PROTÓTIPOS
	void validar(int valor);
	int inserir(no **inicio, no **fim);
	void remover(no **inicio);
	void imprime(no *inicio);
	
	//MAIN
    void main(void){

		time_t 		inicio_simulacao, tempo_atual;
		int 		duracao_simulacao, num_usuarios, num_usuarios_segundo;
		no 			*inicio = NULL, *fim = NULL;
		clock_t 	milisseg_atual;
		struct tm 	*timeinfo;
		char 		opcao;


		textbackground(BRANCO);
		textcolor(VERMELHO);

		printf("Seja bem-vindo ao simulador! \n");


		//QUANTO TEMPO IRÁ DURAR A SIMULAÇÃO????
		printf("Digite quantos segundos tu desejas simular seu processo: ");
		scanf("%d", &duracao_simulacao);

		//VALIDAÇÃO DO HORÁRIO
		validar(duracao_simulacao);


		printf("Digite quantos usuarios tu desejas simular seu processo: ");
		scanf("%d", &num_usuarios);

		//VALIDAÇÃO DO NÚMERO DE USUÁRIOS
		validar(num_usuarios);


		printf("Digite quantos usuarios tu desejas adicionar por segundo em teu processo: ");
		scanf("%d", &num_usuarios);

		//VALIDAÇÃO DO NÚMERO DE USUÁRIOS
		validar(num_usuarios);

		//TEMPO QUE INICIA A SIMULAÇÃO
		time(&inicio_simulacao);
		system("cls");


		do{
			//TEMPO ATUAL DA SIMULAÇÃO
			time(&tempo_atual);
			timeinfo = localtime(&tempo_atual);
			
			gotoxy(0,0);
			printf("Dados do processo iniciado: \n\n- %d usuarios \n- %d usuarios adicionados por segundo \n- %d usuarios por segundos", duracao_simulacao, num_usuarios, num_usuarios_segundo);

			//MOLDANDO HORÁRIO
			gotoxy(0,50);
			printf ("%2d:%2d:%2d", timeinfo -> tm_hour, timeinfo -> tm_min, timeinfo -> tm_sec);

			//MOLDDANDO TEMPO EM SEGUNDOS
			gotoxy(2,50);
			printf("%d segundos", (int) difftime(tempo_atual, inicio_simulacao));

			//MOLDANDO MILISSEGUNDOS
			gotoxy(4,50);
			milisseg_atual = clock();
			printf("%u milissegundos", milisseg_atual);  
			
			
			
			
		
			/*
			unsigned short opcao;

			textcolor(AZUL);
			gotoxy(24,0);
			printf("Pressione 0 para sair... ");
			
	        printf("%c", spin());
			opcao = leitura();
			
			
			*/
	



		}while(((int) difftime((time(&tempo_atual)), inicio_simulacao)) <= duracao_simulacao);




	}
	
	
	
	
	
	
	//FUNÇÕES
	
	
	
	void validar(int valor){
		while(valor <= 0){
		   printf("Este numero eh invalido!\n");
		   printf("Digite novamente: ");
	       scanf("%d", &valor);
		}
	}	


	int inserir(no **inicio, no **fim){
		
		static int chave_da_fila = 0;

	    time_t entrada;
		no *novo = (no *) malloc(sizeof(no));
		if(novo == NULL) return(-1);    //stackoverflow

		novo -> chave = chave_da_fila;
		novo -> entrada = time(&entrada);
		novo -> prox = (* inicio);

        if(!(* inicio)){
            (* fim) -> prox = novo;
            (* fim) = novo;
        }else{
            (* inicio) = (* fim) = novo;
        }
		
		++chave_da_fila;
		return(1);
	}


	void remover(no **inicio){
	    time_t saida;

        if((*inicio) == NULL) printf("ERROR");
        no *aux = (*inicio);
        int N = aux -> chave;
        (*inicio) -> saida = time(&saida);

        printf("O index passou %d segundos na fila! \n", (int) difftime(((*inicio) -> saida),  ((*inicio) -> entrada)));

        (*inicio) = (*inicio) -> prox;
        free(aux);
        printf("O index excluido foi: %d! \n", N);
	}


	void imprime(no *inicio){
		if(inicio != NULL){
			printf("%d. ", inicio -> chave);
			imprime(inicio -> prox);
		}
	}
