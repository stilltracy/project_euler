#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int POWER_OF_7[11]={1,7,7*7,49*7,49*49,49*49*7,49*49*49,49*49*49*7,49*49*49*49,49*49*49*49*7,49*49*49*49*49};
static inline unsigned int count7s(unsigned int n)
{
	int result=0;
	for(int i=10;i>=1;i--)
		result+=n/POWER_OF_7[i];
	return result;
}
unsigned int countIndivisible7(unsigned int n)
{
	unsigned int count=1;
	for(unsigned int i=1;i<n;i++)
	{
		count+=2;
		for(unsigned int j=1;j<i;j++)
		{
			if(count7s(i)<=count7s(j)+count7s(i-j))
				count++;			
		}
	}
	return count;
}

int main(int argc, char * argv[])
{
	int n=atoi(argv[1]);
	unsigned int count=countIndivisible7(n); 
	cout<<count<<endl;
	//count=countIndivisible7(1000000000);
	
	//cout<<count<<endl;
	return 0;
}
