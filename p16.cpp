#include <iostream>
#include <cstring>
using namespace std;
int * power(int base, int index, int * p_size)
{
	int * result=new int[index];
	memset(result,0,index*sizeof(int));
	for(int i=0;i<index;i++)
	{
		cout<<result[i]<<endl;
	}
	cout<<endl;
	*p_size=1;
	result[0]=1;
	int carry=0;
	for(int j=1;j<=index;j++)
	{
		for(int i=0;i<*p_size;i++)
		{
			int d=result[i]*base+carry;
			result[i]=d%10;
			carry=d/10;
			if(i==*p_size-1&&carry!=0)
				(*p_size)++;
			//cout<<result[i];
		}
		//cout<<endl;
		
	}
	return result;
	
}
int main(int argc, char * argv[])
{
	int base=stoi(argv[1]);
	int index=stoi(argv[2]);
	int size=0;
	int sum=0;
	int * result=power(base,index,&size);
	for(int i=0;i<size;i++)
	{
		sum+=result[i];
	}
	cout<<sum<<endl;
}
