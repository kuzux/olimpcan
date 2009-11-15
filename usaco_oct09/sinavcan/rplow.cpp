/*
PROG: rplow
LANG: C++
ID: kuzux921
*/
#include <fstream>
using namespace std;

bool field[240][240];

int main(){
  ifstream in("rplow.in");
  ofstream out("rplow.out");

  int W, H, N; in >> W >> H >> N;
  
  for(int i=0;i<N;i++){
    int xll, yll, xur, yur;
    in >> xll >> yll >> xur >> yur;
    
    for(int j=yll-1;j<yur;j++)
      for(int k=xll-1;k<xur;k++)
        field[j][k]=true;
  }
  
  int res=0;
      
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      if(field[i][j]) res++;
  
  out << res << endl;
  return 0;
}
