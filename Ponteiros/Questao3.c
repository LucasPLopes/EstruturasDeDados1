#include<stdio.h>

void hanoi(int n, char a,char c,char b);
int main(int argc, char argv[])
{
	int n ;
	
	printf("N%cmero de discos: ",163);
	scanf("%i",&n);
	hanoi(n,'A','C', 'X');
	
	
	return 0;
}

void hanoi(int n, char a,char c,char b)
{
	if(n == 1 )
	{
			printf("\nmover disco da torre %c para %c",a,c);
			return ;
	}
	hanoi( n-1, a,b,c);
	printf("\nmover disco da torre %c para %c",a,c);
	hanoi(n-1,b,c,a);
}

