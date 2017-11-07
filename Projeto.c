	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <windows.h>

	#include <conio.h>
	#include <math.h>
	#include "tela.h"
	
	//VARIÁVEIS GLOBAIS 
	int		n_DuracaoGlobal = 0;
	time_t  	t_InicioSimulacao, t_TempoAtual;
	clock_t		milisseg_atual;
    	struct tm 	*timeinfo;
	
	
	//ESTRUTURAS
	typedef struct sFila{
    	int 		n_Registro;
    	time_t 		t_Entrada, t_Saida;
    	struct sFila	*prox;
	} s_Fila;

	typedef struct sServidores{
		int	n_Registro;
		s_Fila 	*sf_Inicio;
    		s_Fila	*sf_Fim;
    		int	n_DuracaoSimulacao, n_QntUsuarios, n_UsuPorSeg, n_UsuTratPorSeg;
	} s_Servidores;

	//PROTÓTIPOS
	void f_Validar(int n_Valor);
	void f_SetServidor(s_Servidores Servidor[], int n_QntServidores);
	void f_GraficoHorario();
	void f_Simulacao(s_Servidores Servidor[], time_t *t_TempoInser, time_t *t_TempoRet);
	
	void f_Inserir(s_Servidores Servidor[], int i);
	void f_Remover(s_Servidores Servidor[], int i);
	void f_Imprimir(s_Servidores Servidor[], int i);

	/*
	char 	f_Spin();
	char 	f_Leitura();
	int 	f_Inserir(no **inicio, no **fim);
	void 	f_Remover(no **inicio);
	void 	f_Imprime(no *inicio);
	*/

	//MAIN
   	void main(void){
       	int					n_QntServidores;
    	unsigned short		f_Retorno;
    	time_t				t_TempoInser = 0, t_TempoRet = 0;
    	char 				d_Opcao;

		textcolor(VERMELHO);

		printf("[(:)] Seja bem-vindo ao Simulador! \n");

		printf("[(:)] Digite quantos servidores tu desejas iniciar neste processo: ");
		scanf("%d", &n_QntServidores);		
		
		//textbackground(BRANCO);
		s_Servidores Servidor[n_QntServidores];
		
		f_SetServidor(Servidor, n_QntServidores);
		
		system("cls");
		
		//TEMPO QUE INICIA A SIMULAÇÃO
		time(&t_InicioSimulacao);
		
		
		do{
			time(&t_TempoAtual);	
			
			//gotoxy(0,0);
			//printf("Dados do processo iniciado: \n\n- %d usuarios \n- %d usuarios adicionados por segundo \n- %d usuarios por segundos", duracao_simulacao, num_usuarios, num_usuarios_segundo);

			f_GraficoHorario();
			printf("\n\n");
			f_Simulacao(Servidor, &t_TempoInser, &t_TempoRet);
			
			
		}while( ((int) difftime((time(&t_TempoAtual)), t_InicioSimulacao)) <= n_DuracaoGlobal);
		
		
		//f_Imprimir(Servidor, 0);
		
	}



	//FUNÇÕES
	
	
	//VALIDAÇÃO DOS DADOS
	
	void f_Validar(int n_Valor){
		while(n_Valor <= 0){
		   printf("[ :(] Infelizmente este numero esta no escopo negativo!\n");
		   printf("[(:)] Digite novamente: ");
	      	   scanf("%d", &n_Valor);
		}
	}

	//INFORMAÇÕES DO SERVIDOR

	void f_SetServidor(s_Servidores Servidor[], int n_QntServidores){
    	int i;
    	for (i=0; i<n_QntServidores; i++){
    		system("cls");
    		printf("[(%d)] Servidor!\n", i);
    		printf("[(%d)] \n", i);
    		printf("[(%d)] Inserindo dados do Servidor [%d] \n", i, i);
			
    		Servidor[i].n_Registro 	= i;
    	        Servidor[i].sf_Inicio	= NULL;
    	        Servidor[i].sf_Fim	= NULL;
			
			printf("[(%d)] Digite quantos segundos tu desejas simular seu processo: ", i);
			scanf("%d", &Servidor[i].n_DuracaoSimulacao);
			printf("\n");
			
			if(Servidor[i].n_DuracaoSimulacao >= n_DuracaoGlobal){
				n_DuracaoGlobal = Servidor[i].n_DuracaoSimulacao;
    		}
			
			printf("[(%d)] Digite quantos usuarios tu desejas simular seu processo: ", i);
			scanf("%d", &Servidor[i].n_QntUsuarios);
			printf("\n");

			printf("[(%d)] Digite quantos usuarios tu desejas adicionar por segundo em teu processo: ", i);
			scanf("%d", &Servidor[i].n_UsuPorSeg);
			printf("\n");

			printf("[(%d)] Digite quantos usuarios tu desejas tratar por segundo em teu processo: ", i);
			scanf("%d", &Servidor[i].n_UsuTratPorSeg);
    	}
	}
	
	//INTERFACE
		
	void f_GraficoHorario(){
			timeinfo = localtime(&t_TempoAtual);

			//MOLDANDO HORï¿½RIO
			gotoxy(0,50);
			printf ("%2d:%2d:%2d", timeinfo -> tm_hour, timeinfo -> tm_min, timeinfo -> tm_sec);

			//MOLDDANDO TEMPO EM SEGUNDOS
			gotoxy(2,50);
			printf("%d segundos", (int) difftime(t_TempoAtual, t_InicioSimulacao));

			//MOLDANDO MILISSEGUNDOS
			gotoxy(4,50);
			milisseg_atual = clock();
			printf("%u milissegundos", milisseg_atual);
	}
	
	
	
	
	//SIMULAÇÃO
	
	void f_Simulacao(s_Servidores Servidor[], time_t *t_TempoInser, time_t *t_TempoRet){
			
			int i = 0;
			//for
					
			if((int) difftime(t_TempoAtual, *t_TempoInser) >= Servidor[i].n_UsuPorSeg){
                	f_Inserir(Servidor, i);
                	time(&*t_TempoInser);
                	//f_Imprimir(Servidor, i);	
            }

			time(&t_TempoAtual);
			
			if(((int) difftime(t_TempoAtual, t_InicioSimulacao)) % Servidor[i].n_UsuTratPorSeg == 0 && t_TempoAtual != *t_TempoRet){
			f_Remover(Servidor, i);
			time(&*t_TempoRet);
			//f_Imprimir(Servidor, i);	
			}
			
	}
	
	
	
	
	
	
	
	
	
	//FUNÇÕES DE MANIPULAÇÃO DA FILA
	
	void f_Inserir(s_Servidores Servidor[], int i){

		static int 	n_RegistroGeralInser = 0;
	 	time_t		t_EntradaFila;
	    
		s_Fila *sNovo = (s_Fila *) malloc(sizeof(s_Fila));
		if(sNovo == NULL)  //stackoverflow

		sNovo -> n_Registro = n_RegistroGeralInser;
		sNovo -> t_Entrada = time(&t_EntradaFila);
        	sNovo -> prox = NULL;
        
        if((Servidor[i].sf_Inicio) != NULL){
            Servidor[i].sf_Fim -> prox = sNovo;
            Servidor[i].sf_Fim = sNovo;
        }else{
            Servidor[i].sf_Inicio = Servidor[i].sf_Fim = sNovo;
        }

		printf("[(-)] Usuario %d entrou na fila do Servidor %d! \n", n_RegistroGeralInser, i);
		printf("[(-)] ...");
		n_RegistroGeralInser++;	
	}


	void f_Remover(s_Servidores Servidor[], int i){
	    time_t t_SaidaFila;

        if(Servidor[i].sf_Inicio == NULL) printf("ERROR \n");
        
        s_Fila *aux = Servidor[i].sf_Inicio;
        int N = aux -> n_Registro;
        
        Servidor[i].sf_Inicio -> t_Saida = time(&t_SaidaFila);
        printf("[(-)] Usuario %d saiu da fila do Servidor %d! \n", aux -> n_Registro, i);
		printf("[(-)] ...");

        Servidor[i].sf_Inicio = Servidor[i].sf_Inicio -> prox;
        free(aux);
	}


	void f_Imprimir(s_Servidores Servidor[], int i){
		if(Servidor[i].sf_Inicio != NULL){
			printf("%d. ", Servidor[i].sf_Inicio -> n_Registro);
			f_Imprimir(Servidor[i].sf_Inicio -> n_Registro, i);
		}
	}
	
	
