#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sort(int a[], int size)
{
	int max_index=0;
	for(int i=0;i<size;i++)
	{
		max_index=i;
		for(int j=i+1;j<size;j++)
		{
			if(a[max_index]<a[j])
			{
				max_index=j;
			}
		}
		if(max_index!=i)
		{
			a[max_index]^=a[i];
			a[i]^=a[max_index];
			a[max_index]^=a[i];
		}
	}
}
int repermutate(int a[], int size)
{
	int high=-1;
	int low=-1;
	for(int i=size-1;i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]<a[j])
			{
				if(j>low)
				{
					high=i;
					low=j;
				}
				break;
			}
		}
	}
	if(high==-1)
	{
		printf("no more move.\n");
		return -1;
	}
	int tmp=a[high];
	for(int k=high;k>low;k--)
	{
		a[k]=a[k-1];
	}
	sort(a+low+1,size-low-1);
	a[low]=tmp;
	return 0;
	
}
void print_array(int * a , int size)
{
	for (int i=0;i<size;i++)
	{
		printf("%d",a[i]);
	}
}
int * generate_array(int n)
{
	int * a=(int *) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		a[i]=n-i;
	}
	return a;
}
int is_prime(int n)
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
int to_int(int * array, int size)
{
	int value=0;
	int weight=1;
	for(int i=size-1;i>=0;i--)
	{
		value+=weight*array[i];
		weight*=10;
	}
	return value;
}
void main(int argc, char * argv[])
{
	int start=atoi(argv[1]);
	for(int i=start;i>0;i--)
	{
		int * array=generate_array(i);
		int has_no_move=0;
		do{
			if(array[i-1]%2!=0)
			{
				int value=to_int(array,i);
				printf("current value =%d\n",value);
				if(is_prime(value))
				{
					printf("found: %d\n",value);
					return;
				}	
			}
			has_no_move=repermutate(array,i);
			

		}while(has_no_move==0);
	}
	
}
