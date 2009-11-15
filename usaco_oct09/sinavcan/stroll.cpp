/*
PROG: stroll
LANG: C++
ID: kuzux921
*/

#include <fstream>
using namespace std;

int paths[1001][2];
int maxlen;

void search(int n, int l){
  if(paths[n][0]) search(paths[n][0], l+1);
  else if(l>maxlen) maxlen = l;
  if(paths[n][1]) search(paths[n][1], l+1);
  else if(l>maxlen) maxlen = l;
}

int main(){
  ifstream in("stroll.in");
  ofstream out("stroll.out");
  
  int N; in >> N;
  for(int i=0;i<N;i++){
    int x; in >> x;
    in >> paths[x][0] >> paths[x][1];
  }
  
  search(1,1);
  out << maxlen << endl;
  
  return 0;
}
