#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <list>
using namespace std;
void read_log(const char * filename, string * log,unsigned int record_count)
{
	ifstream in_file;
	in_file.open(filename);
	int i=0;
	while(in_file)
	{
		in_file>>log[i];
		cout<<log[i]<<endl;
		i++;
		if(i>=record_count)
		 	break;
	}
	cout<<"i="<<i<<endl;
	in_file.close();
}
static char order_table[10][10];
bool less_in_table(const int first, const int second)
{
	return order_table[first][second]=='<'?true:false;
}
string find_shortest_passcode(string * log,  unsigned int record_count)
{
	int i=0;
	list<int> numbers_appeared;
	bool appeared[10];
	memset(order_table,'N',10*10);
	memset(appeared,false,10);
	for(int i=0;i<record_count;i++)
	{
		string record=log[i];
		cout<<"current record:"<<record<<endl;
		for(int j=0;j<record.size();j++)
		{
			int x=record.at(j)-'0';
			if(!appeared[x])
				numbers_appeared.push_back(x);
			appeared[x]=true;
			for(int k=j+1;k<record.size();k++)
			{
				int y=record.at(k)-'0';
				if(order_table[x][y]!='C'&&order_table[y][x]!='<')
				{
					order_table[x][y]='<';
				}
				else
				{
					order_table[x][y]='C';
					order_table[y][x]='C';
				}
			}
		}
	}
	cout<<"order_table:"<<endl;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			cout<<order_table[i][j]<<" ";
		cout<<endl;
	}
	string s="";
	numbers_appeared.sort(less_in_table);
	for( auto it=numbers_appeared.begin();it!=numbers_appeared.end();it++)
		cout<<*it;
	cout<<endl;
	return s;
		
}
int main(int argc, char * argv[])
{
	unsigned int record_length=stoi(argv[2]);
	unsigned int record_count=stoi(argv[3]);
	string * log=new string[record_count];
	read_log(argv[1],log,record_count);
	string passcode=find_shortest_passcode(log,record_count);
	cout<<passcode<<endl;	
}
