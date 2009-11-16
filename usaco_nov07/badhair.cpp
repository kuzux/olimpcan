//SORU 510
//PROGRAM C++
#include <iostream>
#include <fstream>
using namespace std;

int N;
int boy[80000];
int dyn[80000];
int res;


int main(){
  ifstream in("bedhair.in");
  in >> N;
  for(int i=0;i<N;i++) in >> boy[i];
  in.close();

  for(int i=N-2;i>=0;i--){
    int next = i+1;
    while(boy[next]<boy[i]&&next<N){
      dyn[i] += dyn[next]+1;
      next += dyn[next]+1;
    }
    res += dyn[i];
  }

  ofstream out("bedhair.out");

  out << res << endl;
  out.close();
  return 0;
}
