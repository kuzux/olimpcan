/* 
ID: kuzux921
PROG: zerosum
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

int N;
vector<string> Res;

int sum(string s){
  int res = 0;
  int curr = 1;
  for(int i=0;i<N-1;i++){
    if(s[i]==' '){
      curr *= 10;
      if(curr<0) curr -= i+2;
      else curr += i+2;
    }else if(s[i]=='+'){
      res += curr;
      curr = i+2;
    }else if(s[i]=='-'){
      res += curr;
      curr = -(i+2);
    }
  }
  res += curr;
  //cout << s << ": " << res << endl;
  return res;
}

void dfs(string s, int n){
  if(n==0){
    if(sum(s)==0) Res.push_back(s);
    return;
  }
  dfs(s,n-1);
  s[N-1-n]='+';
  dfs(s, n-1);
  s[N-1-n]='-';
  dfs(s,n-1);
}

void output(ostream& out, string s){
  out << 1;
  for(int i=0;i<N-1;i++){
    out << s[i] << i+2;
  }
  out << endl;
}

int main(){
  ofstream out ("zerosum.out");
  ifstream in ("zerosum.in");
 
  in >> N;
  string start;
  for(int i=0;i<N;i++) start += " ";
  dfs(start, N-1);

  for(int i=0;i<Res.size();i++){
    output(out, Res[i]);
  }
  
  return 0;
}

