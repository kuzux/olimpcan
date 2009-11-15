/*
PROG: evenodd
LANG: C++
ID: kuzux921
*/
#include<fstream>
using namespace std;

int main(){
  ifstream in("evenodd.in");
  ofstream out("evenodd.out");
  
  int n; in >> n;
  for(int i=0;i<n;i++){
    int a; in >> a;
    if(a%2) out << "odd";
    else out << "even";
    out << endl;
  }
  return 0;
}
