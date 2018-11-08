struct aviao{
    char nome[7];
	char op[2];
	int combustivel;
	int pista;
};

typedef struct elemento* Lista;

Lista* cria_lista();


void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aviao al);
int tamanho_lista(Lista* li);
int insere_lista_ordenada(Lista* li, struct aviao al);
int remove_lista_inicio(Lista* li);


void reduz_combustivel(Lista* li);
struct aviao retorna_comeco(Lista* li);
int emergencias(Lista* li);

struct aviao retorna_comeco(Lista* li);

void imprime_lista(Lista* li);

void imprime_pousou(struct aviao av, int hr,int min,int sec,int pista);
void imprime_decolou(struct aviao av, int hr,int min,int sec,int  pista);
void imprime_lista_decolagem(Lista* li);
