#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

struct size{
  int w;
  int h;
};

char grid[1000][1000];
bool palin[1000][1000];
size sizes[1000][1000];
int N, M;

inline void calcPalin(int i, int j){
  int b1=i-1, e1=i+1, b2=j-1, e2=j+1;
  int r1=0, r2=0;
  while(b1>=0&&e1<N){
    if(grid[b1][j]!=grid[e1][j]) break;
    r1++;b1--;e1++;
  }
  while(b2>=0&&e2<M){
    if(grid[i][b2]!=grid[i][e2]) break;
    r2++;b2--;e2++;
  }

  sizes[i][j].w = r2+1;
  sizes[i][j].h = r1+1;

  if(r1&&r2) palin[i][j] = true;
}

size maxlen(int y, int x){
  bitset<128> s1;
  bitset<128> s2;
  size res;
  int top;
  s1[grid[y][x]]=1;
  for(int i=sizes[y][x].h-1;i>=0;i--){
    if(top>i) break;
    s1[grid[y+i][x]] = 1;
    s2.reset();
    s2[grid[y][x]]=1;
    for(int j=sizes[y][x].w-1;j>=0;j--){
      if(top>i+j) break;
      s2[grid[y][x+j]] = 1;
      if(s1==s2&&i+j>res.w+res.h){
        res.h = i; res.w = j; top = i+j;
      }
    }
  }
  res.w*=2;res.w++;
  res.h*=2;res.h++;
  return res;
}

int main(){
  ifstream in("palindrom.in");
  ofstream out("palindrom.out");

  in >> N >> M;

  for(int i=0;i<N;i++)
   for(int j=0;j<M;j++) in >> grid[i][j];

  for(int i=1;i<N-1;i++)
    for(int j=1;j<M-1;j++)
      calcPalin(i, j);
  
  int Rw = 0, Rh=0, Ri, Rj;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!palin[i][j]) continue;
      if(sizes[i][j].w+sizes[i][j].h<=Rw+Rh) continue;
      size s = maxlen(i,j);
      if(s.w+s.h>Rw+Rh){
        Rw = s.w; Rh = s.h;
        Ri = i; Rj = j;
      }
    }
  }

  out << Ri+1 << " " << Rj+1 << " " << Rw << " " << Rh << endl;
}

