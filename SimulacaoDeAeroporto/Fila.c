#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

struct elemento{
	struct aviao dados;
    struct elemento *prox;
	
};
typedef struct elemento Elem;

	char voou[] ="aeronave decolou";
	char pousou[] ="aeronave pousou";


Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aviao al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}


int insere_lista_ordenada(Lista* li, struct aviao al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.combustivel < al.combustivel){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

void reduz_combustivel(Lista* li){
		if(li == NULL)
        return ;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
		no->dados.combustivel -= 1;
        no = no->prox;
    }
	printf("\t\tREDUCAO DE COMBUSTIVEL\n");
	}
int consulta_emergencia(Lista* li){
		if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
		if (no->dados.combustivel == 0 )
			cont++;
        no = no->prox;
    }
	return cont;
	}
	
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
	int i =0;
    while(no != NULL){
		printf("[%i] ",i+1);
		printf("Nome: %s\t", no->dados.nome);
		// printf("Pista: %i\n",no->dados.pista);		
		printf("Opcao: %s", no->dados.op);
		printf("%2d\n", no->dados.combustivel);
		
			i++;
			no = no->prox;
    }
}

void imprime_lista_decolagem(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
	int i =0;
    while(no != NULL){
		printf("[%i] ",i+1);
		printf("Nome: %s\t", no->dados.nome);
		// printf("Pista: %i\n",no->dados.pista);		
		printf("Opcao: %s\n", no->dados.op);
		// printf("%2d\n", no->dados.combustivel);
		
			i++;
			no = no->prox;
    }
}



int emergencias(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        if((no->dados.combustivel ) == 0 )
			cont++;
        no = no->prox;
    }
    return cont;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

struct aviao retorna_comeco(Lista* li){
    Elem *no = *li;
	struct aviao av;
       av =no->dados;
        return av;
}

void imprime_pousou(struct aviao av, int hr,int min,int sec, int pista){
	printf("Codigo do voo: %s\n",av.nome);
	printf("Status: %s\n", pousou);
	printf("Horario do inicio do procedimento: %2i:%2i:%2i\n",hr ,min, sec);
	printf("Numero da pista %i\n\n",pista );
}
void imprime_decolou(struct aviao av, int hr,int min,int sec,int pista){
	printf("Codigo do voo: %s\n",av.nome);
	printf("Status: %s\n", voou);
	printf("Horario do inicio do procedimento: %2i:%2i:%2i\n",hr ,min, sec);
	printf("Numero da pista %i\n\n",pista );
}


