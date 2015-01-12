#include <iostream>
using namespace std;

int get_collatz_length(long long n)
{
	if(n==1)
	{
		return 1;
	}
	if(n%2==0)
		return 1+get_collatz_length(n/2);
	else
		return 1+get_collatz_length(3*n+1);
	
}
int find_optimal_start(long long upper_bound, long long * optimal_start)
{
	int max_length=0;
	for(long long i=1;i<upper_bound;i++)
	{
		int length=get_collatz_length(i);
		if(length>max_length)
		{
			max_length=length;
			*optimal_start=i;
		}
	}
	return max_length;
}
int main(int argc, char * argv[])
{
	long long n=stoll(argv[1]);
	long long optimal_start=0;
	int length=find_optimal_start(n,&optimal_start);
	cout<<length<<","<<optimal_start<<endl;
}
