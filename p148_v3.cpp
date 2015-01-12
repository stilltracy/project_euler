#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const unsigned int POWER_OF_7[11]={1,7,7*7,49*7,49*49,49*49*7,49*49*49,49*49*49*7,49*49*49*49,49*49*49*49*7,49*49*49*49*49};
static inline unsigned int count7s(unsigned int n)
{
	int result=0;
	for(int i=10;i>=1;i--)
		result+=n/POWER_OF_7[i];
	return result;
}
unsigned long long countIndivisible7(unsigned int n)
{
	unsigned long long count=0;
	unsigned long long count2=1;
	unsigned int k[11];
	for(unsigned int i=0;i<n;i++)
	{
		unsigned int r=i;
		unsigned long long count_i=1;
		for(int j=10;j>=0;j--)
		{
			k[j]=r/POWER_OF_7[j];
			r=r%POWER_OF_7[j];
			count_i*=k[j]+1;
		}
		count+=count_i;
		/*
		if(i>0)
		{
			count2+=2;
			for(unsigned int j=1;j<i;j++)
			{
				if(count7s(i)<=count7s(j)+count7s(i-j))
					count2++;
			}
		}
		if (count!=count2)
		{
			cout<<i<<" : count: "<<count<<"; count2: "<<count2<<endl;
			break;
		}
		*/
		
	}
	return count;
}

int main(int argc, char * argv[])
{
	int n=atoi(argv[1]);
	unsigned long long count=countIndivisible7(n); 
	cout<<count<<endl;
	//count=countIndivisible7(1000000000);
	
	//cout<<count<<endl;
	return 0;
}
