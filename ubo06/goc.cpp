#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int N, M;
bool mat[10][10];
int yol[10];
int parent[2][10];
int res[2][10];

void read(){
  ifstream in("goc.gir");
  in >> N >> M;

  for(int i=0;i<M;i++){
    int a, b; in >> a >> b;
    mat[--a][--b] = true;
    mat[b][a] = true;
  }
  in.close();
}

void write(){
  int say[2]; say[0] = 0; say[1] = 0;
  for(int i=0;i<N-1;i++){
    if(!yol[i]) continue;
    say[yol[i]-1]++;
  }
  ofstream out("goc.cik");
  
  for(int k=0;k<2;k++){
    out << say[k]+2 << " 1 ";
    backtrack(k);
    for(int i=say[k];i>0;i--) out << res[k][i]+1 << " ";
    out << res[k][0]+1 << endl;
  }

  out.close();
  exit(0);
}

void backtrack(int k){
  int curr = N-1;
  int i=0;
  while(curr){
    res[k][i++] = curr;
    curr = parent[k][curr];
  }
}

void dfs(int p1, int p2){
  if(p1==N-1&&p2==N-1) write();

  int e1 = (p1==N-1)?N-2:0;
  int e2 = (p2==N-1)?N-2:0;

  for(int i=N-1;i>e1;i--){
    if(!mat[p1][i]) continue;
    if(i!=N-1&&yol[i]) continue;
    if(i!=N-1) yol[i] = 1;
    if(i!=p1) parent[0][i] = p1;

    for(int j=N-1;j>e2;j--){
      if(!mat[p2][j]) continue;
      if(j!=N-1&&yol[j]) continue;
      if(j!=N-1) yol[j] = 2;
      if(j!=p2) parent[1][j] = p2;
      
      dfs(i,j);
      
      yol[j] = 0; parent[1][j] = -1;
    }

    yol[i] = 0; parent[0][i] = -1;
  }
}


void process(){
  for(int i=0;i<N;i++) mat[i][i] = 1;
  for(int k=0;k<2;k++)
    for(int i=0;i<N;i++) parent[k][i] = -1;
  dfs(0,0);
}

int main(){
  read();
  process();
}

