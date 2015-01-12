#include <iostream>
#include <cmath>
#include <gmp.h>
using namespace std;
void gcd( mpz_t r, mpz_t a, mpz_t b)
{
	if( mpz_cmp(a, b)<0)
	{
		gcd(r,b,a);
	}else
	{
		mpz_t tmp;
		mpz_init(tmp);
		mpz_tdiv_r(tmp,a,b);
		if(mpz_cmp_ui(tmp,0)==0)
		{
			mpz_set(r,b);
		}
		else
		{
			gcd(r,b,tmp);
		}
	}
}
class fraction{
public:
	mpz_t numerator;
	mpz_t denominator;
	fraction(mpz_t n, mpz_t d)
	{
		mpz_set(this->numerator,n);
		mpz_set(this->denominator,d);
	}
	void operator+=(unsigned long n)
	{
		mpz_t tmp;
		mpz_init(tmp);
		mpz_mul_ui(tmp,this->denominator,n);
		mpz_add(this->numerator,tmp,this->numerator);
	}
	void simplify()
	{
		mpz_t g;
		mpz_init(g);
		gcd(g,numerator,denominator);
		while(mpz_cmp_ui(g,1)!=0)
		{
			mpz_t r;
			mpz_init(r);
			mpz_tdiv_q(r,numerator,g);
			mpz_set(numerator,r);
			mpz_tdiv_q(r,denominator,g);
			mpz_set(denominator,r);
			gcd(g,numerator,denominator);
		}
		cout<<"simplified: "<<numerator<<"/"<<denominator<<endl;
	}
	void inverse()
	{
		mpz_t tmp;
		mpz_init_set(tmp,denominator);
		mpz_set(denominator,numerator);
		mpz_set(numerator,tmp);
	}

};
void sum_of_digits(mpz_t result, mpz_t n)
{
	mpz_t  r;
	mpz_t sum;
	mpz_init_set(r,n);
	mpz_init_set_ui(sum,0);
	while(mpz_cmpabs_ui(r,0)!=0)
	{
		mpz_t q;
		mpz_init(q);
		mpz_tdiv_qr_ui(r,q,r,10);
		mpz_add(sum,sum,q);
	}
	mpz_set(result,sum);
}
/*the sequence->size() == size*/
fraction *calculate_fraction(unsigned long long * sequence, unsigned long long size)
{
	if(size<=1)
	{
		mpz_t n;
		mpz_init_set_ui(n,1);
		mpz_t d;
		mpz_init_set_ui(d,(unsigned long)sequence[0]);
		return new fraction(n,d);
	}
	else
	{
		fraction * f=calculate_fraction(sequence+1,size-1);
		*f+=sequence[0];
		f->inverse();
		f->simplify();
		return f;
	} 	
}
unsigned long long * generate_sequence(unsigned long long size)
{
	unsigned long long * sequence=new unsigned long long[size];
	for(unsigned long long i=0;i<size;i++)
	{
		if(i%3==1)
			sequence[i]=(i/3+1)*2;
		else 
			sequence[i]=1;	
		cout<<sequence[i]<<" ";
	}
	cout<<endl;
	return sequence;
}
int main(int argc, char * argv[])
{
	unsigned long long size=stoll(argv[1]);
	unsigned long long * sequence=generate_sequence(size);
	fraction * f=calculate_fraction(sequence, size);
	*f+=2;
	f->simplify();
	cout<<f->numerator<<"/"<<f->denominator<<endl;
	mpz_t sum_d;
	mpz_init(sum_d);
	sum_of_digits(sum_d,f->numerator);
	cout<<sum_d<<endl;
}
