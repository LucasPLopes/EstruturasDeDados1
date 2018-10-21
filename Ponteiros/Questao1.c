#include<stdio.h>
#define N 2

void fneuronio(double *p, double *e,double l, int num,int *neuronio	);

int main(){
	double pesos[N],entradas[N], limiar;
	int neuronio;
	printf("Limiar: ");scanf("%lf",&limiar);
		
		for(int i = 0; i< N;i++)
		{
		printf("PESOS[%i] : ",i);scanf("%lf",&pesos[i]);printf("\n");
		}
		for(int i = 0; i< N;i++)
		{
		printf("ENTRADAS[%i] : ",i);scanf("%lf",&entradas[i]);printf("\n");
		}
	
	fneuronio(pesos, entradas,limiar, N,&neuronio);
	
	if(neuronio == 1 )
		printf("Neuronio ativado!\n");
	else
		printf("Neuronio inibido!\n");
	return 0;
}

void fneuronio(double *p, double *e,double l, int num,int *neuronio	)
{
		double somap = 0.0;
		
		for(int i =0 ; i < num ;i++ ){
			
			somap+= (*(p +i)) * (*(e + i));
		}
	if(somap > l)
		*neuronio = 1;
	else
	*neuronio = 0;
}	
