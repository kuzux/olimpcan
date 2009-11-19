#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

int N, X, Y;
int start[25000];
int end[25000];

void read(){
  ifstream in("sandcas.in");
  in >> N >> X >> Y;
  for(int i=0;i<N;i++)
    in >> start[i] >> end[i];
  in.close();
}
int Res;

void process(){
  sort(start, start+N);
  sort(end, end+N);
  
  for(int i=0;i<N;i++){
    int diff = end[i] - start[i];
    if(diff<0) Res += (-diff)*Y;
    else Res += diff*X;
  }
}

void write(){
  ofstream out("sandcas.out");
  out << Res << endl;
  out.close();
}

int main(){
  read();
  process();
  write();
  return 0;
}

