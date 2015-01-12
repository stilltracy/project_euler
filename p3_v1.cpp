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
	unsigned int size=1000>n/2?n/2:1000;
	unsigned long long start=2;
	unsigned long long * primes=new unsigned long long[size];
	unsigned long long max_prime_factor=0;
	unsigned long long r=n;
	while(start<n)
	{
		generate_primes(start,primes,size);
		for(long long i= 0;i <size;i++)
		{
			while(r%primes[i]==0)
			{
				max_prime_factor=primes[i];
				r/=primes[i];
				cout<<primes[i]<<";";
			}
			if(r<primes[i])
			{
				if(!is_prime(r))	
				{
					cout<<"impossible:"<<r<<endl;
					exit(1);
				}
				return r>max_prime_factor?r:max_prime_factor;
			}
		}
		start=primes[size-1]+1;
	}
	return 0;
}
int main(int argc, char * argv[])
{
	unsigned long long  n=0;
	n=stoll(argv[1],0,10);
	unsigned long long result=find_max_prime_factor(n);
	cout<<endl<<result<<endl;
	
}
