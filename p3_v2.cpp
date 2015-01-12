#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool is_prime(unsigned long long n)
{
	
	unsigned long long sqrt_n=(unsigned long long)sqrt(n)+1;
	unsigned long long upper_bound=sqrt_n<n-1?sqrt_n:n-1;
	for(unsigned long long i = 2; i<=upper_bound; i++)
	{
		if(n % i==0)
			return false;
	}
	return true;
}
void generate_primes(unsigned long long start, unsigned long long * primes, unsigned long long size)
{
	unsigned long long i=0;
	unsigned long long j=start;
	while(i<size)
	{
		if(is_prime(j))
			primes[i++]=j;
		j++;
	}
}
unsigned long long find_max_prime_factor(unsigned long long n)
{
	unsigned long long max_prime_factor=0;
	unsigned long long r=n;
	unsigned long long sqrt_n=sqrt(n);
	unsigned long long upper_bound=sqrt_n<n-1?sqrt_n:n-1;
	for(unsigned long long i= 2;i <upper_bound;i++)
	{
		while(r%i==0)
		{
			max_prime_factor=i;
			r/=i;
			cout<<i<<";";
		}
		if(r<i)
		{
			if(!is_prime(r))	
			{
				cout<<"impossible:"<<r<<endl;
				exit(1);
			}
			return r>max_prime_factor?r:max_prime_factor;
		}
	}
	return n;
}
int main(int argc, char * argv[])
{
	unsigned long long  n=0;
	n=stoll(argv[1],0,10);
	unsigned long long result=find_max_prime_factor(n);
	cout<<endl<<result<<endl;
	
}
