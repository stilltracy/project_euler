#include <iostream>
#include <fstream>
#include <queue>
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
string find_shortest_passcode(string * log,  unsigned int record_count)
{
	queue<string> q;
	int i=0;
	q.push("");
	for(int i=0;i<record_count;i++)
	{
		string record=log[i];
		cout<<"current record:"<<record<<endl;
		for(int j=0;j<record.size();j++)
		{
			queue<string> tmp_q;
			cout<<"reading i:"<<i<<endl;
			while(!q.empty())
			{
				
				tmp_q.push(q.front());
				cout<<q.front()<<" ";
				q.pop();
				
			}
			cout<<endl;
			cout<<"processing i:"<<i<<endl;
			while(!tmp_q.empty())
			{
				string s=tmp_q.front();
				tmp_q.pop();
				int start=string::npos;
				if(j>0)
				{
					start=s.find_last_of(record.at(j-1));
				}
				if(start==string::npos)
				{
					start=0;
				}
				else	
				{
					start=start+1;
				}
				if(s.find_last_of(record.at(j))!=string::npos)
				{
					q.push(s);
					cout<<"\tj:"<<j<<" remain "<<s<<endl;
					continue;
				}
	
				for(int k=start;k<=s.size();k++)
				{
					string ns=s;
					ns.insert(k,record.substr(j,1));
					cout<<"\tj:"<<j<<" " <<s<<" ---> "<<ns<<endl;		
					q.push(ns);
										
				}
			}
			cout<<endl;
		}
	}
	return q.front();
		
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
