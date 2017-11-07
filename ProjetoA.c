	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <windows.h>

	#include <conio.h>
	#include <math.h>
	#include "tela.h"

	//ESTRUTURAS
	typedef struct sFila{
    	int 			n_Registro;
    	time_t 			t_Entrada, t_Saida;
    	struct sFila	*prox;
	} s_Fila;

	typedef struct sServidores{
		int				n_Registro;
		s_Fila 			*sf_Inicio;
    	s_Fila			*sf_Fim;
    	int				n_DuracaoSimulacao, n_QntUsuarios, n_UsuPorSeg, n_UsuTratPorSeg;

	} s_Servidores;

	//PROTÓTIPOS
	void 	f_Validar(int n_Valor);

	/*
	char 	f_Spin();
	char 	f_Leitura();
	int 	f_Inserir(no **inicio, no **fim);
	void 	f_Remover(no **inicio);
	void 	f_Imprime(no *inicio);
	*/

	//MAIN
    void main(void){
    	clock_t				milisseg_atual;
    	struct tm 	    	*timeinfo;

    	int					n_QntServidores;
    	unsigned short		f_Retorno;
    	time_t				t_InicioSimulacao, t_TempoAtual, t_TempoInser = 0, t_TempoRet = 0;
    	char 				d_Opcao;


		//s_Fila
		//no 			    *inicio = NULL, *fim = NULL;

		textbackground(BRANCO);
		textcolor(VERMELHO);

		printf("[(:)] Seja bem-vindo ao Simulador! \n");

		printf("[(:)] Digite quantos servidores tu desejas iniciar neste processo: ");
		scanf("%d", n_QntServidores);
		f_Validar(n_QntServidores);
		scanf("\n");

		s_Servidores Servidor[n_QntServidores];
		f_setServidor(n_QntServidores, Servidor[]);

	}






	//FUNÇÕES
	void f_Validar(int n_Valor){
		while(n_Valor <= 0){
		   printf("[ :(] Infelizmente este numero esta no escopo negativo!\n");
		   printf("[(:)] Digite novamente: ");
	       scanf("%d", &n_Valor);
		}
	}

	void f_setServidor(int n_Quant, s_Servidores Servidor[]){
    	int i;
    	for (i=0; i<n_Quant; i++){


    		//n_DuracaoSimulacao, n_QntUsuarios, n_UsuPorSeg, n_UsuTratPorSeg;

    		printf("[(%d)] Inserindo dados do Servidor [%d] \n ", i, i);

    		Servidor[i].n_Registro 	= i;
    	    Servidor[i].sf_Inicio	=	NULL;
    	    Servidor[i].sf_Fim		=	NULL;

			printf("[(%d)] Digite quantos segundos tu desejas simular seu processo: ", i);
			scanf("%d", &Servidor[i].n_DuracaoSimulacao);
			validar(Servidor[i].n_DuracaoSimulacao);
			scanf("\n");

			printf("[(%d)] Digite quantos usuarios tu desejas simular seu processo: ", i);
			scanf("%d", &Servidor[i].n_QntUsuarios);
			validar(Servidor[i].n_QntUsuarios);
			scanf("\n");

			printf("[(%d)] Digite quantos usuarios tu desejas adicionar por segundo em teu processo: ", i);
			scanf("%d", &Servidor[i].n_UsuPorSeg);
			validar(Servidor[i].n_UsuPorSeg);
			scanf("\n");

			printf("[(%d)] Digite quantos usuarios tu desejas tratar por segundo em teu processo: ", i);
			scanf("%d", &Servidor[i].n_UsuTratPorSeg);
			validar(Servidor[i].n_UsuTratPorSeg);
			scanf("\n");


    	}
	}


