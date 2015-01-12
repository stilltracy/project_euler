#include <stdio.h>
#include <stdlib.h>
long lattice(int x, int y)
{
	long result=0;
	if(x==1||y==1)//f(x,1)=x+1, f(1,y)=1+y;
	{
		return x+y;
	}
	//x>=2,y>=2
	//for(int i=1;i<x;i++)
	{
		result+=lattice(x-1,y);
	}
	//for(int i=1;i<y;i++)
	{
		result+=lattice(x,y-1);
	}
	return result;
	
}
int main(int argc, char * argv[])
{
	int x=atoi(argv[1]);
	int y=atoi(argv[2]);
	printf("#routes=%ld\n",lattice(x,y));
}
