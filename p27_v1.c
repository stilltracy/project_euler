#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_N 2048
int isPrime(int n)
{
	if(n<0) n=-n;
	int s=(int)sqrt(n)+1;
	for(int i=2;i<=s;i++)
	{
		if (n%i==0)
			return 0;
	}
	return 1;
}
int computeFormula(int n, int a, int b)
{
	return n*(a+n)+b;
}

int longestStreak(int a, int b)
{
	for(int n=0;n<MAX_N;n++)
	{
		int f=computeFormula(n,a,b);
		if(!isPrime(f))
			return n;	
	}
	printf("MAX_N should be larger.(a=%d,b=%d)\n",a,b);
	return MAX_N;
}
void main(int argc, char * argv[])
{
	int r=atoi(argv[1]);
	int max_cprime_count=0;
	int opt_a;
	int opt_b;
	for(int a=1-r;a<r;a++)
	{
		for(int b=(1-r)%2==0?2-r:1-r;b<r;b++)
		{
			int count=longestStreak(a,b);
			if(count>max_cprime_count)
			{
				max_cprime_count=count;
				opt_a=a;
				opt_b=b;
			}	
		}
	}
	printf("longest streak=%d,a=%d,b=%d,ab=%d\n",max_cprime_count,opt_a,opt_b, opt_a*opt_b);
}
