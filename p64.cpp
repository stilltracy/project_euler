#include <iostream>
#include <cassert>
using namespace std;
int igcd(int u, int v)
{
	return (v!=0)?igcd(v,u%v):u;
}
class SqrtWhole{
	private:
		int sqr;
		int co_sqr;
		int whole;
	public:
		SqrtWhole()
		{
		}
		SqrtWhole(int s, int c, int w)
		{
			this->sqr=s;
			this->co_sqr=c;
			this->whole=w;
		}
		SqrtWhole get_conjugate()
		{
			return SqrtWhole(sqr, co_sqr,-whole);
		}
		void simplify()
		{
			if(co_sqr==0)
				sqr=0;
		}
		int gcd()
		{
			return igcd(co_sqr,whole);
		}
		SqrtWhole& operator*=(SqrtWhole& other)
		{
			if(other.sqr==sqr&&other.co_sqr==co_sqr&&other.whole==-whole)
			{
				int p=sqr*co_sqr*other.co_sqr-whole*whole;
				whole=p;
				co_sqr=0;
			}
			else if(other.sqr==0)
			{
				co_sqr*=other.whole;
				whole*=other.whole;
			}
			else if(sqr==0)
			{
				sqr=other.sqr;
				co_sqr=whole;
				whole*=other.whole;
			}
			else	
			{
				assert(false);
			}
			simplify();
			return *this;
		}
		SqrtWhole& operator/=(int d)
		{
			assert(co_sqr%d==0&&whole%d==0);
			co_sqr/=d;
			whole/=d;
			return *this;
		}
		SqrtWhole& operator=(SqrtWhole& other)
		{
			sqr=other.sqr;
			co_sqr=other.co_sqr;
			whole=other.whole;
			return *this;
		}
		bool operator==(SqrtWhole& other)
		{
			return sqr==other.sqr&&co_sqr==other.co_sqr&&whole==other.whole;
		}
		bool operator==(int other)
		{
			return co_sqr*sqr==0&&whole==other;
		}
		void print()
		{
			cout<< co_sqr<<" * s("<<sqr<<") + "<<whole;
		}
		int normalize(int d)
		{
			int delta_whole=0;
			int tsqr=sqr*co_sqr*co_sqr;
			if(co_sqr!=0)
				co_sqr=1;
			while(whole>=0||tsqr>(whole-d)*(whole-d))
			{
				whole-=d;
				delta_whole++;
			}
			if(tsqr==(whole-d)*(whole-d))
			{
				whole=0;
				sqr=0;
				co_sqr=0;
				delta_whole++;
			}
			return delta_whole;
			
		}
		int to_int()
		{
			assert(co_sqr==0);
			return whole;
		}
		
	
};
template<typename T>
class MixedFraction{
	public:
		int whole_part;
		T numerator;
		T denominator;
	
		MixedFraction(int w, T& n, T& d)
		{
			this->whole_part=w;
			this->numerator=n;
			this->denominator=d;
		}
		MixedFraction& operator=(MixedFraction& other)
		{
			whole_part=other.whole_part;
			numerator=other.numerator;
			denominator=other.denominator;
		}
		void rationalize_denominator()
		{
			SqrtWhole c=denominator.get_conjugate();
			denominator*=c;
			numerator*=c;
		}
		void inverse_fraction()
		{
			T tmp=numerator;
			numerator=denominator;
			denominator=tmp;
		}
		void print()
		{
			cout<<whole_part<<" + (";
			numerator.print();
			cout<<")/(";
			denominator.print();
			cout<<")";
		}
		void simplify()
		{
		
			int g1=numerator.gcd();
			int g2=igcd(g1,denominator.to_int());
			numerator/=g2;
			denominator/=g2;
		}
		void normalize()
		{
			int delta_whole=numerator.normalize(denominator.to_int());
			whole_part=delta_whole;
		}	
		bool is_whole()
		{
			return numerator==0;
		}
		bool operator==(MixedFraction& other)
		{
			return whole_part==other.whole_part&&numerator==other.numerator&&denominator==other.denominator;
		}
		bool operator!=(MixedFraction& other)
		{
			return !(*this==other);
		}

};

MixedFraction<SqrtWhole>& next_a(MixedFraction<SqrtWhole>& a)
{
	//a.print();
	//cout<<endl;
	a.inverse_fraction();
	a.rationalize_denominator();
	a.simplify();
	a.normalize();
	//a.print();
	//cout<<endl;
	return a;
}
int main(int argc, char * argv[])
{
	int n=stoi(argv[1]);
	int count_odd_period=0;
	for(int i=2;i<=n;i++)
	{
		SqrtWhole numerator(i,1,0);
		SqrtWhole denominator(0,0,1);
		MixedFraction<SqrtWhole> mf(0,numerator,denominator);
		mf.normalize();
		//cout<<"mf:";
		//mf.print();
		if(mf.is_whole())
			continue;
		//cout<<endl;
		next_a(mf);
		MixedFraction<SqrtWhole> a1=mf;
		int period=1;
		while(next_a(mf)!=a1)
		{
			//cout<<"a1:";
			//a1.print();
			//cout<<endl;
			period++;
		}
		if(period%2==1)
			count_odd_period++;
		//cout<<i<<" period:"<<period<<endl;
	}
	cout<<"#numbers whose periods are odd:"<<count_odd_period<<endl;
}
