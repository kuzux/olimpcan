#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;
int cows[10000];
int dyn[10000][2];
//dyn[i][0] kendinden kucuklerle olan toplam
//dyn[i][1] kendinden buyuklerle olan toplam
int Res;
inline int abs(int x){
  return (x<0)?-x:x;
}

void read(){
  ifstream in("volume.in");
  in >> N;
  for(int i=0;i<N;i++) in >> cows[i];
  in.close();
}

void process(){
  sort(cows,cows+N);
  for(int i=0;i<N;i++) dyn[0][1] += cows[i]-cows[0];
  Res+=dyn[0][1];
  for(int i=1;i<N;i++){
    int diff = cows[i]-cows[i-1];
    dyn[i][0] = dyn[i-1][0];
    dyn[i][0] += i*diff;
    dyn[i][1] = dyn[i-1][1];
    dyn[i][1] -= (N-i)*diff;
    Res += dyn[i][0]+dyn[i][1];
  }
}

void write(){
  ofstream out("volume.out");
  out << Res << endl;
  out.close();
}

int main(){
  read();
  process();
  write();

  return 0;
}
