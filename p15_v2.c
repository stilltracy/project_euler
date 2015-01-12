#include <stdio.h>
#include <stdlib.h>
long long lattice(int x, int y)
{
	//long result=0;
	long long * f=(long long *) malloc(sizeof(long long)*x*y);
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			if(i==0||j==0)
			{
				f[i*x+j]=i+1+j+1;
			}
			else
			{
				//for(int k=0;k<i;k++)
				{
					f[i*x+j]+=f[(i-1)*x+j];
				}
				//for(int k=0;k<j;k++)
				{
					f[i*x+j]+=f[i*x+j-1];
				}
			}
		}
	}	
	return f[(x-1)*x+y-1];
	
}
int main(int argc, char * argv[])
{
	int x=atoi(argv[1]);
	int y=atoi(argv[2]);
	printf("#routes=%lld\n",lattice(x,y));
}
