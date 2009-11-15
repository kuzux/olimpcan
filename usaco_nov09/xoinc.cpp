#include <fstream>
#include <iostream>
using namespace std;

struct Res{
  int ncoin;
  int amount;
};

Res dyn[2000][1000];
int coins[2000];
int sums[2001];
int N;

Res game(int id, int prev){
  if(dyn[id][prev].ncoin) return dyn[id][prev];
  int max=0, maxn=0;

  for(int i=2*prev;i>=1;i--){
    if(id+i>N) break;
    int curr = 0;
    curr = sums[id+i]-sums[id];
    
    Res other = game(id+i, i);
    Res next = game(id+i+other.ncoin, other.ncoin);
    curr += next.amount;
    if(curr>max){
      max = curr;
      maxn = i;
    }
  }
  
  dyn[id][prev].ncoin = maxn;
  dyn[id][prev].amount = max;
  return dyn[id][prev];
}

void fill(){
  for(int i=1;i<N;i++){
    int toplam=0;
    for(int j=N-i;j<N;j++)
      toplam += coins[j];
    int start = i/2;
    if(i%2) start++;
    for(int j=start;j<N;j++){
      dyn[N-i][j].amount = toplam;
      dyn[N-i][j].ncoin = i;
    }
  }
}

int main(){
  ifstream in("xoinc.in");
  ofstream out("xoinc.out");

  in >> N;
  for(int i=0;i<N;i++) in >> coins[i];
  for(int i=1;i<=N;i++)
    sums[i] = sums[i-1]+coins[i-1];

  fill();
  Res r = game(0,1);
  out << r.amount << endl;
}

