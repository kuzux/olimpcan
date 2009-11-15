/* 
PROG: rescue
LANG: C++
ID: kuzux921
*/
#include <fstream>
#include <climits>
using namespace std;
#define abs(x) ((x)>0?(x):-(x))

int N, M;

int Min=INT_MAX, Oi, Oj;

int dist(int Xi, int Xj, int Yi, int Yj){
  //Yi>Xi
  int n = Yi-Xi;
  int ymov = 2*n;
  if(Yj%2) ymov++;
  int xmin, xmax;
  if(Yj%2){
    xmin = Yj-2*n+1;
    xmax = Yj;
  }else{
    xmin = Yj-n-1;
    xmax = Yj;
  }

  if(Xi<xmin){
    return ymov+xmin-Xi;
  }else if(Xi>xmax){
    return ymov+Xi-xmax;
  }else{
    if(Xi%2==Yi%2) return ymov;
    else return ymov+1;
  }
}

int main(){
  ifstream in("rescue.in");
  ofstream out("rescue.out");

  in >> N >> M;
  int Si, Sj;
  in >> Si >> Sj;

  for(int i=0;i<M;i++){
    int Ai, Aj;
    in >> Ai >> Aj;
    int d=INT_MAX;
    if(Ai<Si){
      d = dist(Ai, Aj, Si, Sj);
    }else if(Ai>Si){
      d = dist(Si, Sj, Ai, Aj);
    }else{
      d = abs(Aj-Sj)+1;
    }
    if(d<Min){
      Min = d;
      Oi = Ai;
      Oj = Aj;
    }
    else if(d==Min&&Aj<Oj){
      Min = d;
      Oi = Ai;
      Oj = Aj;
    }
    else if(d==Min&&Aj==Oj&&Ai<Oi){
      Min = d;
      Oi = Ai;
      Oj = Aj;
    }
  }

  out << Oi << " " << Oj << endl;
  out << Min << endl;
}

