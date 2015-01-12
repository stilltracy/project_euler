#include <iostream>
#include <gmpxx.h>
using namespace std;
int main(int argc, char * argv[])
{
	char *  n=argv[1];
	mpz_class i(n);
	while(true)
	{
		mpz_class a=i*(i-1);
		mpz_class  low=0, high=i,x=(low+high)/2;
		for(;low<high;x=(low+high)/2)
		{
			mpz_class b=x*(x-1);
			if(a>2*b)
				low=x+1;
			else if(a<2*b)
				high=x-1;
			else
			{
				cout<<i<<","<<x<<endl;
				return 0;
			}
				

		}
		if(low==high&&a==2*low* (low-1))
		{
			cout<<i<<","<<low<<endl;
			return 0;
		}
		//cout<<i<<endl;
		i++;
		if(i%100000==0)
			cout<<i<<endl;
	}
}
