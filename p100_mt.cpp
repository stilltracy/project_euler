#include <iostream>
#include <gmpxx.h>
#include <pthread.h>
#include <vector>
#include <utility>
#include <thread>
using namespace std;
static mpz_class next_start(0);
static mpz_class range(0);
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
static pair<mpz_class,mpz_class> *answer=NULL;

void * search(void * arg)
{
	pair<mpz_class,mpz_class> * p=(pair<mpz_class,mpz_class> *)arg;
	mpz_class lower_bound=p->first;
	mpz_class upper_bound=p->second;
	while(true)
	{
		for(mpz_class i=lower_bound;i<=upper_bound;i++)
		{
			mpz_class a=i*(i-1);
			mpz_class  low=0, high=i,x=(low+high)/2;
			for(;low<high;x=(low+high)/2)
			{
				
				mpz_class b=x*(x-1);
				if(a>2*b)
					low=x+1;
				else if(a<2*b)
					high=x-1;
				else
				{
					cout<<i<<","<<x<<endl;
					pthread_mutex_lock(&mutex);
					answer=new pair<mpz_class,mpz_class>(i,x);
					pthread_mutex_unlock(&mutex);

					return NULL;
				}
					

			}
			if(low==high&&a==2*low* (low-1))
			{
				cout<<i<<","<<low<<endl;
				pthread_mutex_lock(&mutex);
				answer=new pair<mpz_class,mpz_class>(i,low);
				pthread_mutex_unlock(&mutex);
				return NULL;
			}
			//cout<<i<<endl;
			i++;
			//if(i%100000==0)
				//cout<<i<<endl;
		}
		pthread_mutex_lock(&mutex);
		if(answer!=NULL)
		{
			pthread_mutex_unlock(&mutex);
			return NULL;
		}
		lower_bound=next_start;
		upper_bound=next_start+range;
		next_start=upper_bound;
		cout<<"working on ["<<lower_bound<<","<<upper_bound<<"]"<<endl;
		pthread_mutex_unlock(&mutex);
	}

}
static const unsigned int MAX_RANGE=10000000;
int main(int argc, char * argv[])
{
	string  s(argv[1]);
	next_start=s;
	unsigned long long n=stoll(argv[1]);
	unsigned int ncpu=std::thread::hardware_concurrency();
	if(ncpu==0)
	{
		cout<<"not able to detect ncpu"<<endl;
		ncpu=4;
	}
	cout<<"Using "<<ncpu<<" cores"<<endl;
	pthread_t * threads=new pthread_t[ncpu];
	vector<pair<mpz_class,mpz_class>> args;
	unsigned long long r=n/ncpu;
	range=r>MAX_RANGE?MAX_RANGE:(unsigned int)r;
	for(int i=0;i<ncpu;i++)
	{
		args.push_back(pair<mpz_class,mpz_class>(next_start,next_start+range));
		next_start+=range+1;
	}
	for(int i=0;i<ncpu;i++)
	{
		pthread_create(threads+i,NULL,search,(void *)(&args.at(i)));
	}
	for(int i=0;i<ncpu;i++)
	{
		pthread_join(threads[i],NULL);
	}
	
}
