//SORU 1229
//PROGRAM C++
#include <iostream>
#include <fstream>
using namespace std;

int dyn[2001][1000];
int yetenek[2000];
int N, F;

void read(){
  ifstream in("fristeam.in");
  in >> N >> F;
  for(int i=0;i<N;i++) in >> yetenek[i];
  in.close();
}

void process(){
  dyn[0][0] = 1;
  for(int i=0;i<=N;i++){
    for(int j=0;j<F;j++){
      dyn[i+1][j] += dyn[i][j];
      dyn[i+1][j] %= 100000000;
      int next = (j+yetenek[i])%F;
      dyn[i+1][next] += dyn[i][j];
      dyn[i+1][next] %= 100000000;
    }
  }
}

void write(){
  ofstream out("fristeam.out");
  dyn[N][0]--; dyn[N][0]+=100000000; dyn[N][0]%=100000000;
  out << dyn[N][0] << endl;
  out.close();
}

int main(){
  read();
  process();
  write();
}
