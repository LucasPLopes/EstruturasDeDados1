// arquivo de cabeçalho

struct contato
{
	char nome[101];
	char telefone[11];
	char endereco[101];
	int cep;
	char nascimento[11];
	};

typedef struct elemento * Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

int consulta_lista_nome(Lista*li, char nome[101], struct contato *c );
	
int insere_lista_ordenada(Lista*li, struct contato c );
int tamanho_lista(Lista*li);

int remove_lista(Lista*li, char nome[101]);

void visualizar_lista(Lista*li);

void visualizar_contato(Lista*li, char nome[101]);

void imprime_dados( struct contato c );

struct contato recebe_contato(char nome[101], char telefone[11], char endereco[101], int cep, char nascimento[11]);


void grava_lista_arq(FILE *fp, Lista*li);


void limpa_tela();
void menu();
