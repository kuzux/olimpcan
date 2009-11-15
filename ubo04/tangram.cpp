#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct parca{
  int r, c;
  char kod[26][26];
  int kodsayisi;
}

bool operator <(const Parca p1, const Parca p2){
  return p1.kodsayisi > p2.kodsayisi;
}

int R, C, N;
parca parcalar[26];
char alan[26][26];

void process(){
  sort(parcalar, parcalar+N);
  dfs(0);
}

void dfs(int level){
  for(int i=0;i<R;i++){
    for(int i=0;i<C;i++){
      //böhü, üşeniyom lan o kadar şeyi yazmaya   
    }
  }
}

void read(){
  ifstream in("tangram.inp");
  in >> R >> C >> N;
  for(int i=0;i<N;i++){
    in >> parcalar[i].r >> parcalar[i].c;
    for(int j=0;j<parcalar[i].r;j++){
      for(int k=0;k<parcalar[i].c;k++){
        in >> parcalar[i].kod[j][k];
        if(parcalar[i].kod[j][k]=='0') parcalar[i].kod[j][k] = 0;
        else parcalar[i].kodsayisi++;
      }
    }
  }
}

int main(){
  read();
  process();
}
