/*
ID: kuzux921
LANG: C++
TASK: fracdec
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int rempos[100010]; // where have we seen this remainder?
char decpart[100010]; // the decimal part 

int N, D;
void read(){
  ifstream in("fracdec.in");
  in >> N >> D;
  in.close();
}

stringstream Res;
void process(){
  Res << N/D << '.';
  int num = N;
  int rem = num%D;
  int dig = 0; // number of decimal digits after .
  for(int i=0;i<100010;i++) rempos[i] = -1;
  while(1){
    if(!rem){
      if(dig==0) Res << '0';
      else for(int i=0;i<dig;i++) Res << decpart[i];
      return;
    }
    if(rempos[rem]!=-1){
      int pos = rempos[rem];
      for(int i=0;i<pos;i++) Res << decpart[i];
      Res << '(';
      for(int i=pos;i<dig;i++) Res << decpart[i];
      Res << ')';
      return;
    }
    rempos[rem] = dig;
    num = rem*10;
    decpart[dig] = num/D + '0';
    rem = num%D;
    dig++;
  }
}

void write(){
  ofstream out("fracdec.out");
  const char* s = Res.str().c_str(); int l = Res.str().length();
  for(int i=0;i<l;i++){
    if(i&&i%76==0) out << endl;
    out << s[i];
  }
  out << endl;
  out.close();
}

int main(){
  read();
  process();
  write();
  return 0;
}

