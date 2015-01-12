#include <iostream>
#include <string>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	unsigned long long min=a<b?a:b;
	unsigned long long max_common_divisor=0;
	for(unsigned long long i=1;i<=min;i++)
	{
		if(a%i==0&&b%i==0)
			max_common_divisor=i;
	}
	return max_common_divisor;
}

unsigned long long factorial(unsigned long long  n)
{
	unsigned long long result=1;
	for(unsigned long long i=1;i<=n;i++)
	{
		result*=i;
	}
	return result;
}
unsigned long long get_smallest_multiple(unsigned long long n)
{
	unsigned m=2;
	for(unsigned long long i=3;i<=n;i++)
	{
		m=i*m/gcd(m,i);
	}
	return m;
}
int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	cout<<get_smallest_multiple(n)<<endl;
	return 0;
}
