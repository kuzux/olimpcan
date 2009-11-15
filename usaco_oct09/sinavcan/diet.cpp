/*
PROG: diet
LANG: C++
ID: kuzux921
*/
#include <fstream>
#include <iostream>
using namespace std;

int N, H;
int sizes[500];
int dyn[501];

int main(){
  ifstream in("diet.in");
  ofstream out("diet.out");
  
  in >> H >> N;
  for(int i=0;i<N;i++) in >> sizes[i];
  
  for(int i=1;i<=N;i++){
    for(int j=i;j>=0;j--){
      int curr = sizes[i-1]+dyn[j];
      if(curr>dyn[i]&&curr<H) dyn[i] = curr;
    }
  }
  
  int res=0;
  for(int i=1;i<=N;i++)
    cout << dyn[i] << endl;
  for(int i=1;i<=N;i++)
    if(dyn[i]>res) res = dyn[i];
  out << res << endl;
}
