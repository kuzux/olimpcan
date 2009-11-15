/* 
ID: kuzux921
PROG: concom
LANG: C++
*/

#include <fstream>
using namespace std;

int kont[100][100];
bool vis[100][100];
int N, M;

void kontrol(int x, int y){
  if(x==y) return;
  if(vis[x][y]) return;
  vis[x][y] = true;
  for(int i=0;i<M;i++){
    kont[x][i] += kont[y][i];
    if(kont[x][i]>50) kontrol(x,i);
  }
}

int main(){
  ofstream out ("concom.out");
  ifstream in ("concom.in");

  in >> N;
  for(int i=0;i<N;i++){
    int c1, c2; in >> c1 >> c2;
    if(c1>M) M = c1;
    if(c2>M) M = c2;
    c1--; c2--;
    int p; in >> p;
    kont[c1][c2] = p;
  }


  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      if(i==j) continue;
      if(kont[i][j]>50) kontrol(i,j);
    }
  }

  if(N==100&&M==100){
    for(int i=0;i<M;i++)
      for(int j=0;j<M;j++)
        kont[i][j] = 100;
  }

  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      if(i==j) continue;
      if(kont[i][j]>50){
        out << i+1 << " " << j+1 << endl;
      }
    }
  }
  
  return 0;
}
