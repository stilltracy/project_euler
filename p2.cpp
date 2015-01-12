#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char * argv[])
{
	unsigned int n=atoi(argv[1]);
	unsigned int sum=0;
	unsigned int fib1=1;
	unsigned int fib2=2;
	while(fib1<=n)
	{
		if(fib1%2==0)
			sum+=fib1;
		unsigned int tmp=fib1;
		fib1=fib2;
		fib2=tmp+fib1;
	}
	//sum-=sum_ab;
	cout<<sum<<endl;
	
}
