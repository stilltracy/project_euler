#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
typedef struct pair{
	int base;
	int exp;
} PAIR;

void read_pairs(const char * filename, PAIR * pair_list, int * p_pair_count)
{
	ifstream in_file;
	in_file.open(filename);
	int i=0;
	while(i++,in_file)
	{
		int base=0;
		int exp=0;
		char ch=0;
		in_file>>base>>ch>>exp;
		if(in_file.eof()) break;
		pair_list[i-1].base=base;
		pair_list[i-1].exp=exp;	
		cout<<base<<ch<<exp<<endl;		
	}
	*p_pair_count=i;
	cout<<"i="<<i<<endl;
	in_file.close();	
}
int compare( PAIR * x,  PAIR * y)
{
	int a=x->base;
	int b=x->exp;
	int c=y->base;
	int d=y->exp;
	double m=log(a)/log(c);
	double n=(double)d/(double)b;
	if(m>n)
		return 1;
	else	
		return -1;
}
PAIR * find_max_pair(PAIR * in_pairs, int size)
{
	PAIR * p_max=in_pairs;
	for(int i=1;i<size;i++)
	{
		if(compare(in_pairs+i,p_max)>0)
		{
			p_max=in_pairs+i;
		}
	}
	return p_max;
}
int main()
{
	PAIR * pair_list=new PAIR[1000];
	int size=0;
	read_pairs("p99.in",pair_list,&size);
	PAIR * p_max=find_max_pair(pair_list,size);
	cout<<"max->exponential: "<<p_max->base<<","<<p_max->exp<<" @ line "<< p_max-pair_list<<endl;
	
	return 0;
}
