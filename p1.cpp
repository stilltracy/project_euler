#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char * argv[])
{
	unsigned int n=atoi(argv[1]);
	unsigned int a=atoi(argv[2]);
	unsigned int b=atoi(argv[3]);
	unsigned int sum_ab=0;
	unsigned int sum=0;
	for( unsigned int i=1;i<n;i++)
	{
		if(i%a==0||i%b==0)
			sum+=i;
		if(i%a==0&&i%b==0)
			sum_ab+=i;
		
	}
	//sum-=sum_ab;
	cout<<sum<<endl;
	
}
