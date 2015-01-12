#include <iostream>
using namespace std;
unsigned short * ending_value;

unsigned int get_next(unsigned int current)
{
	unsigned int next=0;
	while(current>0)
	{
		unsigned int d=current%10;
		next+=d*d;
		current/=10;
	}
	return next;
}
/* returns the ending value of the chain derived from start*/
unsigned short derive_chain(unsigned int start)
{
	if(start==1||start==89)
	{
		ending_value[start]=start;
		return start;
	}
	if(ending_value[start]!=0)
		return ending_value[start];
	unsigned int next=get_next(start);
	ending_value[next]=derive_chain(next);
	return ending_value[next];
	
}
int main(int argc, char * argv[])
{
	unsigned int n=stoi(argv[1]);
	ending_value=new unsigned short[n];
	unsigned int count89=0;
	for(int i=1;i<n;i++)
	{
		if(derive_chain(i)==89)
			count89++;
	}
	cout<<count89<<endl;
	delete[] ending_value;
}
