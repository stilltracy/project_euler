#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool is_palindrome(unsigned long long n)
{
	vector<unsigned short> digits;
	unsigned long long r=n;
	while(r>0)
	{
		unsigned short d=r%10;
		digits.push_back(d);
		r/=10;
	}
	int size=digits.size(); 
	for(int  mid_left=(size-1)/2, mid_right=size/2;mid_left>=0&&mid_right<size; mid_left--,mid_right++)
	{
		if(digits.at(mid_left)!=digits.at(mid_right))
			return false;
	}
	return true;
	
}
unsigned long long find_max_palindrome(unsigned long long lower_bound, unsigned long long upper_bound)
{
	unsigned long long max_palindrome=1;
	for(unsigned long long i=lower_bound;i <=upper_bound;i++)
	{
		for(unsigned long long j=lower_bound; j<=i;j++)
		{
			unsigned long long p=i*j;
			if(p>max_palindrome&&is_palindrome(p))
				max_palindrome=p;
			
		}
	}
	return max_palindrome;
}
int main(int argc, char * argv[])
{
	unsigned long long lb =stoll(argv[1]);
	unsigned long long ub =stoll(argv[2]);
	cout<<find_max_palindrome(lb,ub)<<endl;
}
