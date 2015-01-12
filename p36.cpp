#include <iostream>
#include <vector>
using namespace std;
bool is_palindrome(unsigned long long n, int base)
{
        vector<unsigned short> digits;
        unsigned long long r=n;
        while(r>0)
        {
                unsigned short d=r%base;
                digits.push_back(d);
                r/=base;
        }
        int size=digits.size();
        for(int  mid_left=(size-1)/2, mid_right=size/2;mid_left>=0&&mid_right<size; mid_left--,mid_right++)
        {
                if(digits.at(mid_left)!=digits.at(mid_right))
                        return false;
        }
        return true;

}
int main(int argc, char * argv[])
{
	unsigned long long n=stoll(argv[1]);
	unsigned long long sum=0;
	for(unsigned long long i=1;i<n;i++)
	{
		if(is_palindrome(i,10)&&is_palindrome(i,2))
			sum+=i;
	}
	cout<<sum<<endl;
}
