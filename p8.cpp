#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> * read_number(char * filename)
{
	ifstream in_file(filename);
	vector<int> * p_vector=new vector<int>();
	while(in_file)
	{
		char c=0;
		in_file>>c;
		p_vector->push_back(c-'0');
	}
	in_file.close();
	return p_vector;
}
int main(int argc, char * argv[])
{
	char * filename=argv[1];
	int n=stoi(argv[2]);
	vector<int> * p_vector=read_number(filename);
	long long previous_product=-1;
	long long maximum_product=0;
	for(int i=0;i<=p_vector->size()-n;i++)
	{
		if(previous_product==-1)
		{
			previous_product=1;
			for(int j=0;j<=n-1;j++)
			{
				previous_product*=p_vector->at(i+j);
			}
		}
		else
		{	
			if(p_vector->at(i-1)!=0)
			{
				previous_product/=p_vector->at(i-1);
				previous_product*=p_vector->at(i+n-1);
			}
			else
			{
				previous_product=1;
				for(int j=0;j<=n-1;j++)
                        	{
                                	previous_product*=p_vector->at(i+j);
                        	}
			}
		}
		if( previous_product > maximum_product)
			maximum_product=previous_product;
	}
	cout<<maximum_product<<endl;
}
