
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Fila.h"

#define unTempo 5

void esperePor(unsigned int segs){
	unsigned int retTempo = time(0) + segs;
	while(time(0) < retTempo);
	
}


int main(){
	
	char voou[] ="aeronave decolou";
	char pousou[] ="aeronave pousou";

	time_t agora;
	struct tm *antes,*depois;
	time(&agora);
	antes= localtime(&agora);
    srand( (unsigned)time(NULL) );//sequência diferente a toda execução
    struct aviao av,a;
	char nomes[64][7]=
	{
		"VG3001",
		"JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009", "AZ1008",
		"AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880", "AL0012",
		"TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002", "AZ1002",
		"AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403", "AZ1001",
		"LN7003", "AZ1004", "TG1504",  "AZ1005",  "TG1502",  "GL7601",
		"TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392",
		"GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065",
		"LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510",
		"TT1020",  "AZ1098",  "BA2312",  "VG3030",  "BA2304",  "KL5609",
		"KL5610", "KL5611"
	};
	Lista* aproximacao = cria_lista();
    Lista* decolagens = cria_lista();
	

	int NVoos = 20 +(rand()%45);//aleatorieade de voos
		// printf("NVoos: %i\n", NVoos);
	int NAproximacoes =0;
	int NDecolagens = 0;
	int sub=0;
		sub= NVoos -20;
		NAproximacoes = rand()%sub +10;
		NDecolagens =  NVoos - NAproximacoes;
	
	// printf("NAproximacoes: %i\n",NAproximacoes );
	// printf("NDecolagens: %i\n", NDecolagens);
	
	//preparação para carregamento 
    for(int i=0; i < NAproximacoes; i++)
	{
		strcpy(av.nome,nomes[i]);
		av.combustivel= rand()%13;	 
		strcpy(av.op,"A");
		av.pista = 1 + rand()%3;//aproximacoes
		insere_lista_ordenada(aproximacao, av);      
	}
	
	
	for(int i=NAproximacoes ; i < NVoos  ; i++)
	{
		
		strcpy(av.nome,nomes[i]);
		av.combustivel= 12;	 
		av.pista = 1 + rand()%3;//decolagens
		strcpy(av.op,"D");
		insere_lista_final(decolagens, av);      
		
	}
	
	
	
	printf("---------------------------------------------------------------------------------\n");
	printf("Aeroporto Internacional de Brasilia\n");
	printf("Hora Inicial: %02i:%02i:%02i\n",antes->tm_hour,antes->tm_min, antes->tm_sec);
	printf("Fila de Pedidos: [codigo do voo - P/D - prioridade]\n");
	printf("NVoos: %i\n",NVoos);
	printf("Naproximacoes: %i\n",NAproximacoes);
	printf("NDecolagens: %i\n",NDecolagens);
	printf("---------------------------------------------------------------------------------\n");
	printf("Listagem de eventos:\n\n");
	imprime_lista(aproximacao);
	imprime_lista_decolagem(decolagens);
int sec= antes->tm_sec, min= antes->tm_min,hr =antes->tm_hour, tempo_simulacao =0, t_s=0;
int pista1=0,pista2=0, pista3=0;
int pistas_livres=0, tempo=0;
		int contador =0;
	 while(tamanho_lista(aproximacao)!=0 && tamanho_lista(decolagens)!=0)
	 {	
		
			
		
		 if(min >=60)
				{
					min -=60;
					hr++;
				}
 
			
		if(contador/10==1)
		 {
			 contador-=10;
			 reduz_combustivel(aproximacao);
			 
		 }
			
			
					
		if(tamanho_lista(aproximacao) ==0 &&tamanho_lista(decolagens) ==0  )
		{
			
			break;
		}
		
		
			int emerg=0;
			emerg= emergencias(aproximacao);	
		// if(emerg >0)
			// printf("Emergencias: %i \n\n", emerg);
		
		
		//tratamento de emergencias
		if( emerg>0)
		{
			
			// break;
			printf( "ALERTA GERAL DE DESVIO DE AERONAVE\n\n");
			pistas_livres = 0;
			if(pista3==0)
			{
				
				if(tamanho_lista(aproximacao)==0)
					continue;
				pistas_livres++;
				av = retorna_comeco(aproximacao);
				tempo_simulacao+=3;
				
				contador += 3;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =3;
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				remove_lista_inicio(aproximacao);
				insere_lista_final(decolagens,av);
				imprime_pousou(av, hr, min,sec,3);
				// min+=3;
				pista3 += 3;
			}
			// else
				// printf("Pista 3 ocupada!\n");
					
			if(pista2==0){
				
				if(tamanho_lista(aproximacao)==0)
					continue;
				pistas_livres++;
				av = retorna_comeco(aproximacao);
				tempo_simulacao+=3;
				
				contador += 3;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =2;
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				remove_lista_inicio(aproximacao);
				insere_lista_final(decolagens,av);
				imprime_pousou(av, hr, min,sec,2);
				pista2+=3;
			// min+=3;
			
			}
			// else
				// printf("Pista 2 ocupada!\n");
			
			if(pista1==0){
					
				if(tamanho_lista(aproximacao)==0)
					continue;
				pistas_livres++;
				av = retorna_comeco(aproximacao);
				tempo_simulacao+=3;
				
				contador += 3;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =1;
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				remove_lista_inicio(aproximacao);
				insere_lista_final(decolagens,av);
				imprime_pousou(av, hr, min,sec,1);
				// min+=3;
				pista1+=3;
			
			
			}
				// else
					// printf("Pista 1 ocupada!\n");
			// printf("Pistas livres: %i\n", pistas_livres);
			if(pistas_livres > 0)
				min+=3;
			for(int i = emerg; i > pistas_livres; i--)
			{	
				if( tamanho_lista(aproximacao)==0)
					break;
				
				av = retorna_comeco(aproximacao);
				int temp= remove_lista_inicio(aproximacao);
				printf("Caiu: %s\n",av.nome);
			}
			pistas_livres =0;
					
		}
		
		//fim do tratamento das emergencias
		

		if(contador/10==1)
	 {
			 contador-=10;
			 reduz_combustivel(aproximacao);
			 
		 }
		
			//
			//pista 3 decolagem ou pouso de emergencias
			//testa se há uma pelo menos um aviao com 0 de combutível, se há 
			// faz o pouso se não libera decolagem

		if( pista3 ==0 && emergencias(aproximacao) ==0 ){
				
			if( tamanho_lista(decolagens)!=0)
			{
				
				pistas_livres++;
				av = retorna_comeco(decolagens);
				tempo_simulacao+=2;
				
				contador += 2;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =3;
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				remove_lista_inicio(decolagens);
				
				imprime_decolou(av, hr, min,sec,3);
				min+=2;
				pista3+=2;
				
				
			}else{
				// pista3 livre e ocorreu uma emergencia
				
				av = retorna_comeco(aproximacao);
				tempo_simulacao+=3;
				contador += 3;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =3;
				remove_lista_inicio(aproximacao);
				insere_lista_final(decolagens,av);
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				imprime_pousou(av, hr, min,sec,3);
				min+=3;
				pista3 += 3;				
				
			}
			
		}
			//
			//pista 2 decolagem ou pouso aleatoria
			//
if( pista2 ==0 ){
			int aleatoria = rand()%2;
				if(tamanho_lista(decolagens) ==0)
					aleatoria =1;
			
			if( aleatoria == 0 && tamanho_lista(decolagens)!=0)
			{
				
				
				av = retorna_comeco(decolagens);
				tempo_simulacao+=2;
				
				contador += 2;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =2;
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				remove_lista_inicio(decolagens);
				imprime_decolou(av, hr, min,sec,2);
				min+=2;
				pista2+=2;
				
				
			}else{
				
				
				if(tamanho_lista(aproximacao)==0)
					continue;
				av = retorna_comeco(aproximacao);
				tempo_simulacao+=3;
				
				contador += 3;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =2;
				remove_lista_inicio(aproximacao);
				insere_lista_final(decolagens,av);
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				imprime_pousou(av, hr, min,sec,2);
				pista3 += 3;
				min+=3;
			}
			
		}
			//
			//pista 1 decolagem ou pouso aleatoria
			//
			if( pista1 ==0 ){
			int aleatoria = rand()%2;
				if(tamanho_lista(decolagens) ==0)
					aleatoria =1;
				
			if( aleatoria == 0 && tamanho_lista(decolagens)!=0)
			{
				
				
				av = retorna_comeco(decolagens);
				tempo_simulacao+=2;
				
				contador += 2;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =2;
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				remove_lista_inicio(decolagens);
				
				imprime_decolou(av, hr, min,sec,1);
				min+=2;
				pista1+=2;
				
				
			}else{
				
				if(tamanho_lista(aproximacao)==0)
					continue;
				
				av = retorna_comeco(aproximacao);
				tempo_simulacao+=3;
				
				contador += 3;
				av.combustivel = 12;
				strcpy(av.op, "D");
				av.pista =1;
				remove_lista_inicio(aproximacao);
				insere_lista_final(decolagens,av);
				 if(min >=60)
						{
							min -=60;
							hr++;
						}
				imprime_pousou(av, hr, min,sec,1);
				pista1 += 3;
				min+=3;
			}
			
		}
			
		
		
		
		
		
		if(contador/10==1)
		 {
			 contador-=10;
			 reduz_combustivel(aproximacao);
			 
		 }
		 
	
		
		if(tamanho_lista(aproximacao) ==0 &&tamanho_lista(decolagens) ==0  )// || tamanho_lista(decolagens)==0)
		{
			
			break;
		}
		
		
			pista1--;
			pista2--;
			pista3--;
			
			
	// tempo_simulacao++;
	 // min++;	
	 // esperePor(1);
	 // printf("Horario: %2i:%2i:%2i\n",hr ,min, sec);
		
	 }	
	printf("Fim de simulacao, tempo: %i min\n",tempo_simulacao);
	libera_lista(decolagens);
    libera_lista(aproximacao);
	 
	return 0;
}
