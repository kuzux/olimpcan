/*
PROG: papaya
LANG: C++
ID: kuzux921
*/
#include <fstream>
using namespace std;

int jungle[40][40];
int W, H;

int main(){
  ifstream in("papaya.in");
  ofstream out("papaya.out");
  
  in >> H >> W;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      in >> jungle[i][j];
      
  int res = 0;
  int i = 0, j = 0;
  while(1){
    res += jungle[i][j];
    jungle[i][j] = 0;
    if(i==H-1&&j==W-1) break;
    int max = 0;
    int nexti=i, nextj=j;
    if(i&&jungle[i-1][j]>max){
      max = jungle[i-1][j];
      nexti = i-1;
      nextj = j;
    }
    if(i&&jungle[i][j-1]>max){
      max = jungle[i][j-1];
      nexti = i;
      nextj = j-1;
    }
    if(i!=H-1&&jungle[i+1][j]>max){
      max = jungle[i+1][j];
      nexti = i+1;
      nextj = j;
    }
    if(j!=W-1&&jungle[i][j+1]>max){
      max = jungle[i][j+1];
      nexti = i;
      nextj = j+1;
    }
    i = nexti;
    j = nextj;
  }
  
  out << res << endl;
  return 0;
}
