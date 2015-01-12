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

int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	int count=1, i=3;
	while(count<n)
	{
		if(is_prime(i))
			count++;
		i+=2;
	}
	cout<<i-2<<endl;
}
