/*
PROG: echo
LANG: C++
ID: kuzux921
*/
#include <fstream>
using namespace std;

int longest(string s1, string s2){
  int res=0;
  int l1=s1.length(), l2=s2.length();
  int m=(l1<l2)?l1:l2;
  for(int i=1;i<=m;i++){
    if(s1.substr(0,i)==s2.substr(l2-i,i)) res = i;
  }
  return res;
}

int main(){
  ifstream in("echo.in");
  ofstream out("echo.out");
  
  string s1, s2; in >> s1 >> s2;
  int r1=longest(s1,s2), r2=longest(s2,s1);
  out << max(r1,r2) << endl;
  return 0;
}
