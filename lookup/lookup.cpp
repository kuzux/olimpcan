//SORU 1230
//PROGRAM C++
#include <fstream>
using namespace std;

int boy[100000];
int next[100000];
int N;

void read(){
  ifstream in("lookup.in");
  in >> N;
  for(int i=0;i<N;i++)
    in >> boy[i];
  in.close();
}

void process(){
  for(int i=0;i<N;i++) next[i] = i+1;
  for(int i=N-2;i>=0;i--){
    while(boy[i]>=boy[next[i]]&&next[i]<N)
      next[i] = next[next[i]];
  }
  for(int i=0;i<N;i++){
    if(next[i]==N) next[i]=0;
    else next[i]++;
  }
}

void write(){
  ofstream out("lookup.out");
  for(int i=0;i<N;i++) out << next[i] << endl;
  out.close();
}

int main(){
  read();
  process();
  write();
  return 0;
}
