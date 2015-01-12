#include <iostream>
#include <vector>
using namespace std;
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
bool is_pandigital(vector<unsigned short> * digits, int n)
{
	//vector<unsigned short> * digits=to_digits(n);
	if(digits->size()!=n)
		return false;
	for(int i=0;i<digits->size();i++)
	{
		int min_index=i;
		for(int j=i+1;j<digits->size();j++)
		{
			if(digits->at(j)<digits->at(min_index))
			{
				min_index=j;
			}
		}
		if(min_index!=i)
		{
			digits->at(min_index)^=digits->at(i);
			digits->at(i)^=digits->at(min_index);
			digits->at(min_index)^=digits->at(i);
		}

	}
	//digits->size() == n
	for(int i=0; i<n;i++)
	{
		if(digits->at(i)!=i+1)
			return false;	
	}
	return true;
	
}
vector<unsigned short> * get_identity(unsigned long long p, unsigned long long m)
{
	unsigned long long n=p/m;
	vector<unsigned short> * digits_m=to_digits(m);
	vector<unsigned short> * digits_n=to_digits(n);
	vector<unsigned short> * digits_p=to_digits(p);
	vector<unsigned short> * identity=new vector<unsigned short>();
	int i=0;
	int size_m=digits_m->size();
	int size_n=digits_n->size();
	int size_p=digits_p->size();
	for(i=0;i<size_m;i++)
		identity->push_back(digits_m->at(i));
	for(;i<size_m+size_n;i++)
		identity->push_back(digits_n->at(i-size_m));
	for(;i<size_m+size_n+size_p;i++)
		identity->push_back(digits_p->at(i-size_m-size_n));
	delete digits_m;
	delete digits_n;
	delete digits_p;
	return identity;
	
}
int main(int argc, char * argv[])
{
	unsigned long long sum=0;
	for(int p=1234; p<=9876;p++)
	{
		for(int m=1; m<=98; m++)
		{
			if(p%m!=0)
				continue;
			vector<unsigned short > * identity=get_identity(p,m);
			if(is_pandigital(identity,9))
			{
				sum+=p;
				break;
			}
		}
		
	}
	cout<<"sum:"<<sum<<endl;
}
