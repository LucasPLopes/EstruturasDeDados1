#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h" //inclui os Protótipos
#define tam1 101
#define tam2 15


int limite_comparador = 15;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    struct contato dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

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

int consulta_lista_nome(Lista* li, char nome[tam1], struct contato *c ){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && (strstr(no->dados.nome, nome) != NULL))
	{
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *c  = no->dados;
        return 1;
    }
}


int insere_lista_ordenada(Lista* li, struct contato c ){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = c ;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && strncmp(atual->dados.nome, c.nome,limite_comparador)< 0){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int remove_lista(Lista *li, char nome[101]){
	
	if((li)==NULL)
		return 0;
	if((*li)==NULL)//lista vazia
		return 0;
	Elem *no = *li;
	while(no != NULL &&(strstr(no->dados.nome, nome)== NULL)){
		no = no->prox;
	}
	
	if(no == NULL)
		return 0;
	
	if(no->ant == NULL)
		*li=no->prox;
	else
		no->ant->prox = no->prox;
	if(no->prox != NULL)//não é o último
		no->prox->ant = no->ant;
		
	free(no);
	return 1;
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

void visualizar_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Nome: %s\n",no->dados.nome);
        
        no = no->prox;
    }
}

void imprime_dados(struct contato c )
{
	printf("Nome: %s\n", c.nome);
	printf("Telefone: %s\n",c.telefone);
	printf("Endereco: %s\n", c.endereco);
	printf("CEP: %i\n", c.cep);
	char nasc[10] = {};
	printf("Nascimento: %c%c%c%c%c%c%c%c%c%c\n", c.nascimento[0],c.nascimento[1],'/',c.nascimento[3],c.nascimento[4],'/',c.nascimento[6],c.nascimento[7],c.nascimento[8],c.nascimento[9]);
	printf("$\n");
	
	
	
}

void visualizar_contato(Lista* li, char nome[tam1]){
    limpa_tela();
	if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
		if(strstr(no->dados.nome,nome)!=NULL)
			imprime_dados(no->dados);        
        no = no->prox;
		
    }
}

struct contato recebe_contato(char nome[tam1], char telefone[tam2], char endereco[tam1], int cep, char nascimento[tam2])
{
	struct contato c;
	strcpy(c.nome, nome);
	strcpy(c.telefone, telefone);
	strcpy(c.endereco, endereco);
	c.cep = cep;// int 
	strcpy(c.nascimento, nascimento);
	
	return c;
}

void menu()
{
	printf("\t\tAgenda de contatos\n");
	printf("\t\tMenu\n");
	printf("1 -Inserir novo contato\n");
	printf("2 -Listar contatos\n");
	printf("3 -Tamanho\n");
	printf("4 -Buscar contato\n");
	printf("5 -Remover contato\n");
		
	printf("0 -Sair\n");
	
	printf("Opcao: ");
	
}


void grava_lista_arq(FILE *fp, Lista*li)
{
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL)
	{
		fflush(fp);
        fprintf(fp,"%s\n%s\n%s\n%i\n%s\n$\n",
		(no)->dados.nome,(no)->dados.telefone, (no)->dados.endereco, (no)->dados.cep,(no)->dados.nascimento);	
        no = no->prox;
    
	}
	printf("Lista gravada!");
}

void limpa_tela(){
					system("cls||clear");
}
