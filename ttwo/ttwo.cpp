/* 
ID: kuzux921
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define north 0
#define east 1
#define south 2
#define west 3

struct obj{
  int i, j, d; 
};

char map[10][10];

void step(obj& o){
  switch(o.d){
    case north:
      if(o.i==0||map[o.i-1][o.j]=='*') o.d++;
      else o.i--;
      break;
    case east:
      if(o.j==9||map[o.i][o.j+1]=='*') o.d++;
      else o.j++;
      break;
    case south:
      if(o.i==9||map[o.i+1][o.j]=='*') o.d++;
      else o.i++;
      break;
    case west:
      if(o.j==0||map[o.i][o.j-1]=='*') o.d=0;
      else o.j--;
      break;
  }
}

int main(){
  ofstream out ("ttwo.out");
  ifstream in ("ttwo.in");

  obj farmer;
  obj cow;
  farmer.d = north;
  cow.d = north;
  
  for(int i=0;i<10;i++){
    for(int j=0; j<10;j++){
      in >> map[i][j];
      if(map[i][j]=='F'){
        farmer.i = i;
        farmer.j = j;
        map[i][j] = '.';
      }
      if(map[i][j]=='C'){
        cow.i = i;
        cow.j = j;
        map[i][j] = '.';
      }
    }
  }

  int i;
  for (i = 0; i < 10000; i++) {
    if(farmer.i==cow.i&&farmer.j==cow.j){
      out << i << endl;
      return 0;
    }
    step(farmer);
    step(cow);
  }

  out << 0 << endl;
  return 0;
}
