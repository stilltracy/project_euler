#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
const int ROMAN_VALUES[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
map<string, int> roman_to_arab;
map<int,string> arab_to_roman;
static inline void init_maps()
{
	roman_to_arab["I"]=1;
	roman_to_arab["IV"]=4;
	roman_to_arab["V"]=5;
	roman_to_arab["IX"]=9;
	roman_to_arab["X"]=10;
	roman_to_arab["XL"]=40;
	roman_to_arab["L"]=50;
	roman_to_arab["XC"]=90;
	roman_to_arab["C"]=100;
	roman_to_arab["CD"]=400;
	roman_to_arab["D"]=500;
	roman_to_arab["CM"]=900;
	roman_to_arab["M"]=1000;
	arab_to_roman[1]="I";
	arab_to_roman[4]="IV";
	arab_to_roman[5]="V";
	arab_to_roman[9]="IX";
	arab_to_roman[10]="X";
	arab_to_roman[40]="XL";
	arab_to_roman[50]="L";
	arab_to_roman[90]="XC";
	arab_to_roman[100]="C";
	arab_to_roman[400]="CD";
	arab_to_roman[500]="D";
	arab_to_roman[900]="CM";
	arab_to_roman[1000]="M";
}
vector<string> *read_numbers(const char * filename)
{
	ifstream in_file(filename);
	int i=0;
	vector<string> * p_numbers=new vector<string>();
	while(i++,in_file)
	{
		string *record=new string();
		in_file>>*record;
		p_numbers->push_back(*record);
		cout<<*record<<endl;
	}
	in_file.close();
	return p_numbers;
}
unsigned int value_of(string str)
{
	unsigned int value=0;
	for(int i=0;i<str.size();i++)
	{
		if(i<str.size()-1&&roman_to_arab.find(str.substr(i,2))!=roman_to_arab.end())
		{
			value+=roman_to_arab.at(str.substr(i,2));
			i++;
		}
		else
		{
			value+=roman_to_arab.at(str.substr(i,1));
		}
	}
	return value;
}
string * get_minimum_str(string str)
{
	string * p_min_str=new string();
	unsigned int value=value_of(str);
	for(int i=0;i<13;i++)
	{
		if(value<ROMAN_VALUES[i])
		{
			continue;
		}
		for(int j=1;j<=value/ROMAN_VALUES[i];j++)
		{
			p_min_str->insert(p_min_str->size(),arab_to_roman.at(ROMAN_VALUES[i]));
		}
		value=value%ROMAN_VALUES[i];
	}
	return p_min_str;
}
int main(int argc, char * argv[])
{
	init_maps();
	char * filename=argv[1];
	vector<string> * str_numbers=read_numbers(filename);
	int digit_savings=0;
	for(auto it=str_numbers->begin();it!=str_numbers->end();it++)
	{
		int old_count=it->size();
		string * p_new_str=get_minimum_str(*it);
		int new_count=p_new_str->size();
		int savings=old_count-new_count;
		assert(savings>=0);
		digit_savings+=savings;
	}
	cout<<digit_savings<<endl;
	
}
