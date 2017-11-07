	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <windows.h>

	typedef struct tno{
    	int chave;
    	time_t entrada, saida;
    	struct tno *prox;
	} no;

	int inserir(int N, no **inicio, no **fim);
    void remover(no **inicio);

    void main(void){
        //localtime para fazer o horário atual.

		time_t inicio_simulacao, tempo_atual;
		int duracao_simulacao;
		no *inicio = NULL, *fim = NULL;

		printf("Seja bem-vindo ao simulador \n");
		printf("Digite quantos segundos tu desejas simular seu processo: ");
		scanf("%d", &duracao_simulacao);

		while(duracao_simulacao <= 0){
            printf("Este numero eh invalido")
            printf("Digite quantos segundos tu desejas simular seu processo: ");
            scanf("%d", &duracao_simulacao);
		}


		do{
            unsigned short

            printf("  Menu de opcoes:\n\n");
			printf("   1.Inserir um no! \n   2.Imprimir um no! \n   3.Soma dos valores do ponteiro! \n   4.Imprimindo com recursividade! \n   5. Imprimindo ao contrario com recursividade! \n   6. Removendo o no! \n   0.Sair \n\n\n");
			printf(" Digite uma opcao: ");
			scanf("%i", &opcao);
			switch(opcao){
				case 1:
					printf("Digite um valor para adicionar: ");
					scanf("%i", &N);

					retorno = inserir(int N, no **inicio, no **fim);

					if(retorno == 1) printf("O registro: %d foi adicionado com sucesso no endereco %d! \n\n", N, (* inicio));
					else printf("Erro!");

					break;
				case 2:
					remover(no **inicio);
					break;
			}

			printf("Digite algo para prosseguir: \n");
	        scanf("%s", &resp);

            system("cls");





		}while((int) difftime((time(tempo_atual)), inicio_simulacao) <= duracao_simulacao);




	}

	int inserir(int N, no **inicio, no **fim){
	    time_t entrada;
		no *novo = (no *) malloc(sizeof(no));
		if(novo == NULL) return(-1);    //stackoverflow

		novo -> chave = N;
		novo -> entrada = time(&entrada);
		novo -> prox = (* inicio);

        if(!(* inicio)){
            (* fim) -> prox = novo;
            (* fim) = novo;
        }else{
            (* inicio) = (* fim) = novo;
        }

		return(1);
	}

	void remover(no **inicio){
	    time_t saida;

        if((*inicio) == NULL) printf("ERROR");
        no *aux = (*inicio);
        int N = aux -> chave;
        (*inicio) -> saida = time(saida);

        printf("O index passou %d segundos na fila! \n", (int) difftime(((*inicio) -> saida),  ((*inicio) -> entrada)));

        (*inicio) = (*inicio) -> prox;
        free(aux);
        printf("O index excluido foi: %d! \n", N);
	}
