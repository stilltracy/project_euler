#include <stdio.h>
#include <stdlib.h>
int array[10]={0,1,2,3,4,5,6,7,8,9};
void sort(int a[], int size)
{
	int min_index=0;
	for(int i=0;i<size;i++)
	{
		min_index=i;
		for(int j=i+1;j<size;j++)
		{
			if(a[min_index]>a[j])
			{
				min_index=j;
			}
		}
		if(min_index!=i)
		{
			a[min_index]^=a[i];
			a[i]^=a[min_index];
			a[min_index]^=a[i];
		}
	}
}
void repermutate(int a[], int size)
{
	int high=-1;
	int low=-1;
	for(int i=size-1;i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]>a[j])
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
		exit(0);
	}
	int tmp=a[high];
	for(int k=high;k>low;k--)
	{
		a[k]=a[k-1];
	}
	sort(a+low+1,size-low-1);
	a[low]=tmp;
	return;
	
}
void print_array(int * a , int size)
{
	for (int i=0;i<size;i++)
	{
		printf("%d",a[i]);
	}
}
int test_array[4]={3,8,4,1};
void main(int argc, char * argv[])
{
	int order=atoi(argv[1]);
	for(int i=1;i<order;i++)
	{
		repermutate(array,10);
		//printf("%7d:",i);
		//print_array(array,10);
		//printf("\n");
	}
		printf("%7d:",order);
		print_array(array,10);
		printf("\n");
	
}
