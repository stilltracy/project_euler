#include <iostream>
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

/* test whether n could be written as a + 2*b^2, where a is prime
n should be an odd composite positive number*/
bool goldbach_holds(unsigned long long n)
{
	unsigned long long max_b=n/2;
	for(unsigned long long i=1;i<max_b;i++)
	{
		long long a=n-2*i*i;
		if(a<=1)
			break;	
		if(is_prime(a))
			return true;
	}
	return false;
}
int main(int argc, char * argv[])
{
	unsigned long long n=9;
	do{
		if(is_prime(n))
			continue;
		if(!goldbach_holds(n))
		{
			cout<<n<<endl;
			break;
		}
	}while(n+=2);
}
