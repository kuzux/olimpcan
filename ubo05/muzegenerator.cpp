#include <iostream>
#include <fstream>
#include <cstdlib>

#define MAX 50
#define K 2
#define MAXCHAR 26
#define MAXKOMSU 10
#define INTENSITY 9
#define MINNOTKOMSU 5
#define INPUTFILE "muze10.gir"

using namespace std;

int used[MAX+1];
int queue[MAX+1];
int visited[MAX+1];
int toPrint[MAX*MAX+1][2];
char toPrintC[MAX*MAX+1];

void process()
{
	int tail=MAX;
	int node;
	int M=0;
	ofstream OU;
	OU.open(INPUTFILE,ios::out);
	for(int i=0;i<MAX;i++)
		queue[i]=i;
	for(int i=0;i<MAX;i++)
	{
		int pos=rand()%tail;
		node=queue[pos];
		queue[pos]=queue[--tail];
		used[node]=1;
		for(int j=0;j<MAX;j++)
			visited[j]=0;
		int komsu=rand()%MAXKOMSU;
		if(tail>MINNOTKOMSU && komsu==0)
			komsu++;
		while(komsu>tail)
			komsu/=2;
		while(komsu)
		{
			int komsu_no;
			do
				komsu_no=rand()%MAX;
			while(visited[komsu_no]==1 || used[komsu_no]==1);
			komsu--;
			visited[komsu_no]=1;
			for(int j=0;j<MAXCHAR;j++)
				if(rand()%100<INTENSITY)
				{
					char blk='z'-j;
					toPrint[M][0]=node;
					toPrint[M][1]=komsu_no;
					toPrintC[M++]=blk;
					//OU << node << " " << komsu_no << " " << blk << endl; 
				}
		}
	}
	OU << MAX << " " << M << " " << K << endl;
	for(int i=0;i<M;i++)
	{
		OU << toPrint[i][0] << " " << toPrint[i][1] << " " << toPrintC[i] << endl;
	}
	OU.close();
}

int main()
{
	process();
	return 0;
}
