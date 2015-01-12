#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
bool is_prime(unsigned long long n)
{
	if(n<2)
		return false;
        unsigned long long sqrt_n=(unsigned long long)sqrt(n)+1;
        unsigned long long upper_bound=sqrt_n<n-1?sqrt_n:n-1;
        for(unsigned long long i = 2; i<=upper_bound; i++)
        {
                if(n % i==0)
                        return false;
        }
        return true;
}
void add_to_container(vector<unsigned short> * digits, unsigned short d)
{
        digits->push_back(d);
}

unsigned long long value_of(vector<unsigned short> * digits, int head_index,int base)
{
        int size=digits->size();
        unsigned long long weight=1;
        unsigned long long value=0;
        for(int i=0;i<size;i++)
        {
                value+=digits->at((i+head_index)%size)*weight;
                weight*=base;
        }
        return value;
}

template <typename T>
T* to_digits(unsigned long long n, int base)
{
        T *digits=new T();
        unsigned long long r=n;
        while(r>0)
        {
                unsigned short d=r%base;
                add_to_container(digits,d);
                r/=base;
        }
        return digits;
}

void generate_permutations(int n, vector<unsigned short> * array, vector<vector<unsigned short> *> * p_permutations)
{
	if(n==1)
	{
		vector<unsigned short> * p=new vector<unsigned short>();
		*p=*array;
		p_permutations->push_back(p);
		/*
		for(int i=0;i<p->size();i++)
		{
			cout<<p->at(i);	
		}
		cout<<endl;
		*/
	}
	else
	{
		for(int i=0; i<n;i++)
		{
			int j=0;
			generate_permutations(n-1,array, p_permutations);
			if (n%2==1)
			{
				j=i;
			}
			
			unsigned short tmp=array->at(n-1);
			array->at(n-1)=array->at(j);
			array->at(j)=tmp;
			
		}
	}
}
bool is_in(vector<int> v, int m)
{
	for(auto it=v.begin();it!=v.end();it++)
	{
		if(*it==m)
			return true;
	}
	return false;
} 
int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	int base=stoi(argv[2]);
	int length=stoi(argv[3]);
	unsigned long long lower_bound=1;
	for(int i=1;i<n;i++)
	{
		lower_bound*=base;
	}
	/*
	vector<vector<unsigned short>*> permutations;
	vector<unsigned  short> * digits=to_digits<vector<unsigned short>>(1234,10);
	generate_permutations(4,digits,&permutations);
	*/
	for(unsigned long long i=lower_bound;i<lower_bound*base;i++)
	{
		if(is_prime(i))
		{
			vector<int> has_seen;
			has_seen.push_back(i);
			int nr_primes=1;
			string str=to_string(i);
			vector<unsigned short> * digits=to_digits<vector<unsigned short>>(i,base);
			vector<unsigned short> tmp;
			tmp=*digits;
			vector<vector<unsigned short>*> permutations; 
			generate_permutations(n,&tmp,&permutations);
			for(auto it=permutations.begin();it!=permutations.end();it++)
			{
				vector<unsigned short> * permutation=*it;
				
				unsigned long long value=value_of(permutation,0,base);
				if(value>i&&!is_in(has_seen,value)&&is_prime(value))
				{
					//cout<<value<<endl;
					nr_primes++;
					str+=to_string(value);
					has_seen.push_back(value);
				}
				delete permutation;
			}
			if(nr_primes>=length)
			{
				map<int,set<int> *> d_counts;
				bool is_arithmetic_seq=true;
				for(int x=0;x<has_seen.size();x++)
				{
					for(int y=x+1;y<has_seen.size();y++) 
					{
						int d=abs(has_seen.at(x)-has_seen.at(y));
						if(d_counts.find(d)==d_counts.end())
							d_counts[d]=new set<int>();
						//cout<<has_seen.at(x)<<","<<has_seen.at(y)<<endl;
						d_counts[d]->insert(has_seen.at(x));
						d_counts[d]->insert(has_seen.at(y));
					}
				}
				for(auto it=d_counts.begin();it!=d_counts.end();it++)
				{
					if(it->second->size()>=length)
					{
						for(auto it2=it->second->begin();it2!=it->second->end();it2++)
						{
							cout<<*it2<<" ";
						}
						cout<<endl;
					}
				}
			}

			delete digits;
		}
	}
	
}
