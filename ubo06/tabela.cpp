#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool curr[5][5];
bool next[5][5];
bool init[5][5];

int N, K;
void read(){
  ifstream in("tabela.gir");

  in >> N >> K;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      in >> init[i][j];

  in.close();
}

void write(){
  ofstream out("tabela.cik");
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      out << curr[i][j];
    out << endl;
  }
  
  out.close();
  exit(0);
}

bool same(){
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(init[i][j]!=curr[i][j]) return false;
  return true;
}

void step(){
  int upi, upj, righti, rightj;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i){ upi = i-1; upj = j; }
      else{ upi = N-1; if(j!=N-1) upj=j+1; else upj = 0; }
      if(j!=N-1){ righti = i; rightj = j+1; }
      else{ rightj = 0; if(i!=N-1) righti = i+1; else righti = 0; }

      if(curr[upi][upj]==curr[righti][rightj]) next[i][j] = !curr[i][j];
    }
  }
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      curr[i][j] = next[i][j];
}

void final(int k){
  for(int i=0;i<k;i++)
    step();
  write();
}

void process(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      curr[i][j] = init[i][j];
      next[i][j] = init[i][j];
    }
  }

  for(int i=0;i<K;i++){
    step();
    if(same()){
      int mod = i+1;
      if(K%mod<K-i) final(K%mod);
    }
  }

  write();
}

int main(){
  read();
  process();
}

