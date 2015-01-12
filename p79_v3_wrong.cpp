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
	memset(order_table,'N',10*10);
	string passcode="";
	for(int i=0;i<record_count;i++)
	{
		string record=log[i];
		cout<<"current record:"<<record<<endl;
		for(int j=0;j<record.size();j++)
		{
			int x=record.at(j)-'0';
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
			auto it=passcode.begin();
			while(it!=passcode.end()&&less_in_table(*(it++)-'0',x));
			if(*it!=x+'0')
				passcode.insert(it,x+'0');

		}
	}
	return passcode;
		
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
