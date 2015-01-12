#include <iostream>
using namespace std;
int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	int sum=0;
	int sqr_sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
		sqr_sum+=i*i;
	}
	cout<<sum*sum-sqr_sum<<endl;
}
