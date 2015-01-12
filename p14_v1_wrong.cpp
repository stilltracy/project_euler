#include <iostream>
using namespace std;
int find_optimal_start(int end, int upper_bound, int * p_start)
{
	if(end>upper_bound)
	{
		*p_start=end/2;
		return 0;
	}
	int start_left=0;
	int length=find_optimal_start(end*2,upper_bound,&start_left);
	cout<<end<<endl;
	if(end-1<3||(end-1)%3!=0||((end-1)/3)%2==0)
	{
		*p_start=start_left;	
		return length;
	}
	if((end-1)/3==1)
	{
		if(length>1)
		{
			*p_start=start_left;
		}
		else
		{
			*p_start=1;
			length=1;
		}
		return length+1;
	}
	int start_right=0;	
	int length_right=find_optimal_start((end-1)/3,upper_bound,&start_right);
	if(length_right>length)
	{
		length=length_right;
		*p_start=start_right;
	}	
	else	
	{
		*p_start=start_left;
	}
	return length+1;
	
}

int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	int optimal_start=0;
	int length=find_optimal_start(1,n,&optimal_start);
	cout<<length<<","<<optimal_start<<endl;
}
