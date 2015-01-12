#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

void add_to_container(vector<unsigned short> * digits, unsigned short d)
{
	digits->push_back(d);
}
void add_to_container(forward_list<unsigned short> * digits, unsigned short d)
{
	digits->push_front(d);
}
template <typename T>
T* to_digits(unsigned long long n)
{
	T *digits=new T();
	unsigned long long r=n;
	while(r>0)
	{
		unsigned short d=r%10;
		add_to_container(digits,d);
		r/=10;
	}
	return digits;
}
void sort_digits(vector<unsigned short> * digits)
{
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
}
void sort_digits(forward_list<unsigned short> * digits)
{
	digits->sort();
}

template<typename T>
bool is_pandigital(T * digits, int n)
{
	//vector<unsigned short> * digits=to_digits(n);
	sort_digits(digits);
	//digits->size() == n
	int i=1;
	for(auto it=digits->begin();it!=digits->end();i++,++it)
	{
		if(*it!=i)
			return false;	
	}
	if(i!=n+1)
		return false;
	return true;
	
}
forward_list<unsigned short> * concat(forward_list<unsigned short> * digits_list[], int size )
{
	forward_list<unsigned short> * result=new forward_list<unsigned short>();
	for(int i=0;i<size;i++)
	{
		result->splice_after(result->end(),*(digits_list[i]));
	}
	return result;
}
vector<unsigned short> * concat(vector<unsigned short> * digits_list[], int size)
{
	vector<unsigned short> * result=new vector<unsigned short> ();
	for(int i=0;i<size;i++)
	{
		result->insert(result->end(),digits_list[i]->begin(), digits_list[i]->end());
	}
	return result;
}
template<typename T>
T * get_identity(unsigned long long p, unsigned long long m)
{
	unsigned long long n=p/m;
	T ** digits_list=new T*[3]; 
	digits_list[0]=to_digits<T>(m);
	digits_list[1]=to_digits<T>(n);
	digits_list[2]=to_digits<T>(p);
	T * identity  =concat(digits_list,3);
	delete[] digits_list;
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
			vector<unsigned short > * identity=get_identity<vector<unsigned short>>(p,m);
			if(is_pandigital<vector<unsigned short>>(identity,9))
			{
				sum+=p;
				break;
			}
		}
		
	}
	cout<<"sum:"<<sum<<endl;
}
