#include<stdio.h>
#define N 10

void recebe_notas(double *notas, int qnt,int *APR);
void conta_notas(int * APR, int qnt,int* apr, int *rep);
int percent_aprov(int *apr, int*rep);
void cadast_notas(double *Notas, int qnt);


int main(){
	double  *pnotas, notas[N];
	int aprovados =0 ,reprovados = 0;
	int	percent, APR[N];
	pnotas = notas;
	
	cadast_notas(pnotas,N);
	recebe_notas(notas,N, APR);

	
	conta_notas(APR,N, &aprovados,&reprovados);
	
	// percent = percent_aprov(&aprovados,&reprovados);
	
	
	printf("Quantidade de aprovados : %i\n",aprovados);
	printf("Quantidade de reprovados : %i\n",reprovados);
	printf("Percentual de aprovados : %5.2lf\n", 100.0*(double)aprovados/(double)(aprovados + reprovados));
	printf("Percentual de reprovados : %5.2lf\n", 100.0*(double)reprovados/(double)(aprovados + reprovados));

		percent = 100.0*(double)aprovados/(double)(aprovados + reprovados) > 50.0? 1: 0;
	
	
	if( percent == 1)
	printf("Mais da metade da turma aprovada\n");


	


return 0;
}

void recebe_notas(double *notas, int qnt,int *APR){
	
	
	for(int i= 0; i< qnt;i++){
		if( *(notas +i) >=6.0)
			*(APR +i) = 1;
		else
			*(APR +i) = 0;
		
	}
	

} 

void conta_notas(int * APR, int qnt,int* apr, int *rep){
	
	for( int i = 0; i< qnt; i++)
	{
			if(*(APR + i) == 1)
				(*apr) += 1;
			else	
				(*rep) += 1;
		
	}
}


int percent_aprov(int *apr, int*rep)
{
	double percent = *apr + *rep;
	if( (double)*apr/ percent > 50.0)
		return 1;
	else 
		return 0;
}

void cadast_notas(double *Notas, int qnt){
	for( int i = 0; i< N; i++)
	{
		printf("NOTA[%d] : ", i+1);
		scanf("%lf",(Notas +i));		
	}
	// for( int i = 0; i< N; i++)
		// printf("[%2.2lf] ", *(Notas +i));
	// printf("\n");
	
}
