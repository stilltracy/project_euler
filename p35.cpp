#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool is_prime(unsigned long long n);
bool is_circular_prime(unsigned long long n);
unsigned long long value_of(vector<unsigned short> * digits, int head_index);
vector<unsigned short> * to_digits(unsigned long long n);

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

bool is_circular_prime(unsigned long long n)
{
	if(!is_prime(n))
	{
		return false;
	}
	vector<unsigned short> * digits=to_digits(n);
	for(int i=1;i<=n-1;i++)
	{
		unsigned long long value=value_of(digits,i);
		if(!is_prime(value))
			return false;
	}
	return true;
	
}
unsigned long long value_of(vector<unsigned short> * digits, int head_index)
{
	int size=digits->size();
	unsigned long long weight=1;
	unsigned long long value=0; 
	for(int i=0;i<size;i++)
	{
		value+=digits->at((i+head_index)%size)*weight;
		weight*=10;
	}
	return value;
}
vector<unsigned short> * to_digits(unsigned long long n)
{
	vector<unsigned short> *digits=new vector<unsigned short>();
	unsigned long long r=n;
	while(r>0)
	{
		unsigned short d=r%10;
		digits->push_back(d);
		r/=10;
	}
	return digits;
}
int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	int count=0;
	for(int i=2;i<n;i++)
	{
		if(is_circular_prime(i))
		{
			//cout<<i<<endl;
			count++;	
		}
	}
	cout<<"count:"<<count<<endl;
}
