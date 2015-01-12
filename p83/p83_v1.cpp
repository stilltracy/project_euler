#include <iostream>
#include <fstream>
#include <sstream>
#define INFINITY 0x7FFFFFFF
#define M 80
#define N 80
using namespace std;
int ** read_matrix(const char * filename, int m, int n)
{
	ifstream in_file(filename);
	int ** matrix=new int *[m];
	for(int i=0;i<m;i++)
	{
		matrix[i]=new int[n];
	} 
	if(in_file.is_open())
	{
		string line;
		int i=0;
		while(getline(in_file, line))
		{
			if(i>=m) break;
			istringstream iss(line);
			for(int j=0;j<n;j++)
			{
				string s;
				getline(iss, s, ',');
				stringstream ss(s);
				ss>>(matrix[i][j]);
			} 
			i++;
		}
	}
	in_file.close();
	cout<<"read complete"<<endl;
	return matrix;
}

void free_matrix(int ** matrix, int m)
{
	for(int i=0;i<m;i++)
		delete[] matrix[i];
	delete[] matrix;
}
int min_path_sum(int ** matrix, int m, int n)
{

	int * *table=new int *[m];
	for(int i=0;i<m;i++)
	{
		table[i]=new int[n];
		for(int j=0;j<n;j++)
			table[i][j]=INFINITY;
	}
	int result=INFINITY;
	int * *unvisited_nodes=new int *[m*n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			unvisited_nodes[i*n+j]=table[i]+j;
	}
	//for(int i=0;i<m;i++)// nodes in the first column are neighbors of the virtual start point.
	{
		table[0][0]=matrix[0][0];
	}
	
	while(1)
	{
		int * p_min_node=NULL;
		int min_i=-1;
		int min_j=-1;
		for(int i=0;i<m*n;i++)
		{
			if(unvisited_nodes[i]==NULL)//the slot for a node is set to NULL after the node is marked as visited.
				continue;
			if( p_min_node==NULL)
			{
				p_min_node=unvisited_nodes[i];
				min_i=i/n;
				min_j=i%n;
			}
			else
			{
				if(*p_min_node > * unvisited_nodes[i])
				{
					min_i=i/n;
					min_j=i%n;
					p_min_node=unvisited_nodes[i];
				}
			}
			
		}
		if(p_min_node==NULL)//no more nodes to visit
		{
			// end Dijkstra
			break;
		}	
		else//use p_min_node as the current node
		{
			if(min_i>0)//up move
			{
				int tentative_distance=table[min_i][min_j]+matrix[min_i-1][min_j];
				if(tentative_distance < table[min_i-1][min_j])
				{
					table[min_i-1][min_j]=tentative_distance;
				}
			}

			if(min_i<m-1)//down move
			{
				int tentative_distance=table[min_i][min_j]+matrix[min_i+1][min_j];
				if(tentative_distance < table[min_i+1][min_j])
				{
					table[min_i+1][min_j]=tentative_distance;
				}
			}
			if(min_j>0)//left move
			{
                                int tentative_distance=table[min_i][min_j]+matrix[min_i][min_j-1];
                                if(tentative_distance < table[min_i][min_j-1])
                                {
                                        table[min_i][min_j-1]=tentative_distance;
                                }
			}
			if(min_j<n-1)//right move
			{
				int tentative_distance=table[min_i][min_j]+matrix[min_i][min_j+1];
				if(tentative_distance < table[min_i][min_j+1])
				{
					table[min_i][min_j+1]=tentative_distance;
				}
			}
			unvisited_nodes[min_i*n+min_j]=NULL;
		}
	}
	
/*	for(int i=0;i<m;i++)
	{
		if(table[i][n-1]<result)
			result=table[i][n-1];
	}*/
	result=table[m-1][n-1];
	delete[] unvisited_nodes;
	free_matrix(table,m);
	return result;
}
int main()
{
	int ** matrix =read_matrix("p83.in",M,N);
	int min_sum=min_path_sum(matrix,M,N);
	cout<< min_sum<<endl;
	return 0;
}
