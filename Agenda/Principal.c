#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Agenda.h"


int main(){
	
	Lista * li;
	
	li = cria_lista();
	FILE *fp;
	fp= fopen("contatos.txt","r");
	
	if(!fp)
	{
		printf("Erro na abertura do arquivo\n");
		
	}
	
	
		
	char temp[105];
	int cont =1;
	fflush(fp);
	struct contato cc;
    while (fgets(temp, sizeof(temp), fp))
	{
        if( cont == 1)
		{
			
			strcpy(cc.nome, temp);
			cont++;
			
		}
		else if( cont == 2)
		{
			char temp2[105];
			strcpy(temp2, temp);
			strncpy(cc.telefone, temp2,10);
			cont++;
			
		}else if( cont == 3)
		{
			
			strcpy(cc.endereco, temp);
			cont++;
		}
		else if( cont == 4)
		{
			cc.cep = atoi(temp);
			cont++;
		}else if( cont == 5)
		{

			strcpy(cc.nascimento, temp);
			cont++;
		}else
		{cont = 1;
			int c ; 
			c =strlen(cc.nome);
			cc.nome[c -1] =' ';
			c =strlen(cc.nascimento);
			cc.nascimento[c -1] =' ';
			c =strlen(cc.endereco);
			cc.endereco[c -1] =' ';
			imprime_dados(cc);
			insere_lista_ordenada(li, cc);
		
		}
		
    }
		
	fclose(fp);

	int op;
	// system("clear||cls ");
	
	MENU:
	DEFAULT:
	menu();
	fflush(stdin);
	scanf("%i",&op);
	
	switch (op)
	{
		struct contato c;
		case 1:
		{
			printf("Nome: ");
			fflush(stdin);
			gets(c.nome);
			
			
			fflush(stdin);
			printf("Telefone (xxxxx-xxxx): ");
			fflush(stdin);
			gets(c.telefone);
			
			
			fflush(stdin);
			printf("Endereco: ");
			fflush(stdin);
			gets(c.endereco);
			
			
			printf("CEP: ");
			fflush(stdin);
			scanf("%d",&c.cep);
			
			
			printf("Nascimento (dd/mm/aaaa): ");
			fflush(stdin);
			gets(c.nascimento);
			
		
			insere_lista_ordenada(li,c );
			
			goto MENU;
		}
		break;
		
		case 2:
		{
			limpa_tela();
			visualizar_lista(li);
			goto MENU;
		}
		break;
		case 3:
		{
			limpa_tela();
			printf("%i Contatos cadastrados\n",tamanho_lista(li));
			goto MENU;
		}break;
		case 4:
		{
			char str[100];
			printf("Buscar: ");
			fflush(stdin);
			gets(str);
			visualizar_contato(li, str);
				goto MENU;	
		}break;
		
		case 5: 
		{
			printf("Remover: ");
			char str[101];
			fflush(stdin);
			fscanf(stdin, "%[^\n]s",str);
			while(1)
			{
				static int num = 1;
				if(remove_lista(li,str)==1)
				{
				printf("[%i]contato removido!\n",num);
					++num;
				}
				else
				{
					printf("contato nao removido!\n");
					break;
				}
			}
			
			goto MENU;
		}
		break;
		
		case 0:
		{
			
			
			
			
			{
				FILE * fp ;
					fp= fopen("contatos.txt","w");
					if(!fp)
					{
					printf("Erro na abertura do arquivo, fim de programa\n");
					exit(1);
					}
				
				grava_lista_arq(fp,li);
					
				libera_lista(li);
				fclose(fp);
			}
			printf("fim de programa!!\n");
			return 0;

		}	

			default: {
				limpa_tela();
				printf("opcao invalida!!");
				goto DEFAULT;
			}
	}
	
	return 0;
	
}

