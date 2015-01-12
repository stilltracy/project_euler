#include <stdio.h>
#include <math.h>
int count_powerful_digits()
{
	int sum = 0;
	for (int y =1; y<10;y++)
	{
		int n =0;
		long long x=0;
		for( n=1; pow(10/(double)y, n)<=10; n++)
		{
			sum++;
			//x=pow(y,n);
			printf("y=%d,n=%d\n",y,n);
			
		}
		
		//printf("y=%d, n=%d\n",y, n);
	}
	return sum;
}

void main()
{
	int sum=count_powerful_digits();
	printf("count : %d\n", sum);
}
