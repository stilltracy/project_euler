#include <iostream>
#include <vector>
#include <forward_list>
#include <cassert>
using namespace std;
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
template<typename T, typename S>
void print(S prefix, const T * v)
{
	cout<<prefix;
	for(auto it=v->begin(); it!=v->end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

template<typename T>
bool is_pandigital(T * ds, int n)
{
	vector<unsigned short> digits=*ds;
	print("before:",ds);
	sort_digits(&digits);
	print("after:",ds);
	//digits->size() == n
	int i=1;
	for(auto it=digits.begin();it!=digits.end();i++,++it)
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
/* if reverse== true, the vectors will be concatenated in reverse order*/
vector<unsigned short> * concat(vector<vector<unsigned short> *> digits_list, bool reverse)
{
	vector<unsigned short> * result=new vector<unsigned short> ();
	for(auto it =digits_list.begin();it!=digits_list.end();it++)
	{
		auto p=result->end();
		if(reverse)
			p=result->begin();
		result->insert(p,(*it)->begin(),(*it)->end());
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
	unsigned long long max_number=0;
	unsigned long long optimal_i=0;
	unsigned long long optimal_n=0;
	for(unsigned long long i=1; i<=9876;i++)
	{
		unsigned short digits_count=0;
		int n=0;
		vector<vector<unsigned short>*> digits_list; 
		while(digits_count<9)
		{
			n++;
			vector<unsigned short> * digits=to_digits<vector<unsigned short>>(i*n);	
			digits_count+=digits->size();	
			digits_list.push_back(digits);
			
		}
		if(digits_count>9||n<=1)
			continue;
		assert(digits_count==9);
		vector<unsigned short> * cproducts=concat(digits_list,true);
		if(is_pandigital<vector<unsigned short>>(cproducts, 9))
		{
			unsigned long long value=value_of(cproducts,0);
			if(value>max_number)
			{
				max_number=value;
				optimal_i=i;
				optimal_n=n;
			}
		}

		
		
	}
	cout<<"max_number:"<<max_number<<endl;
	cout<<"i:"<<optimal_i<<endl;
	cout<<"n:"<<optimal_n<<endl;
}
