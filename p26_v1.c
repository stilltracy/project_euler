#include <stdio.h>
#include <stdlib.h>
char * *  getDecimals(int n)
{
	char * * array=(char  * *)malloc(sizeof(char *)*(n-2));

	for(int i =0 ; i<n-2; i++)
	{
		int d=i+2;
		double decimal=100000000000000000.0/(double)d;
		array[i]=(char *) malloc(32*sizeof(char));
		sprintf(array[i],"%lf",decimal);
		printf("%s\n",array[i]);
	}
	
}
void main(int argc, char * argv[])
{
	int n=atoi(argv[1]);
	getDecimals(n);
}
