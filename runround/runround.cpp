/* 
ID: kuzux921
PROG: runround
LANG: C++
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

bool runround(char x[], int nd){
  int i = 0;
  bool visited[10];
  bool digits[10];
  for(int j=0;j<nd;j++) visited[j] = false;
  for(int j=0;j<10;j++) digits[j] = false;
  for(int j = 0; j<nd; j++){
    visited[i] = true;
    int k = (i+x[i]-'0')%nd;
    digits[x[i]-'0'] = true;
    if(j==nd-1){
      if(k) return false;
    }
    else if(visited[k]){
      return false;
    }
    else if(digits[x[k]-'0']){
      return false;
    }
    i = k;
  }
  for(int j=0;j<nd;j++){
    if(!visited[j]) return false;
  }
  return true;
}

int main(){
  ofstream out ("runround.out");
  ifstream in ("runround.in");
  int S;
  in >> S;



  char num[10];
  for(int i=S+1;i<100000000;i++){
    int len = sprintf(num,"%d", i);
    if(runround(num,len)){
      out << num << endl;
      break;
    }
  }

  
  return 0;
}
