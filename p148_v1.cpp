#include <iostream>
using namespace std;
static inline unsigned int count7s(unsigned int n)
{
	return n/7;
}
unsigned int countIndivisible7(unsigned int n)
{
	unsigned int count=0;
	for(unsigned int i=1;i<=n;i++)
	{
		for(unsigned int j=1;j<i;j++)
		{
			if(count7s(i)<=count7s(j)*2)
				count++;			
		}
	}
	return count;
}

int main()
{
	unsigned int count=countIndivisible7(100); 
	cout<<count<<endl;
	count=countIndivisible7(1000000000);
	
	cout<<count<<endl;
	return 0;
}
