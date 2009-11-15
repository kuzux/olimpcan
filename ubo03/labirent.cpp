#include <fstream>

struct State{
  int priority;
  int i0, j0;
  int i1, j1;
};

bool operator < (const State s1, const State s2){
  return s1.priority < s2.priority;
}

int R, C;
int E0, E1;
bool labs[2][10][10];
pair<int, int> cikislar[2][100];
pair<int, int> robot[2];

void input(){
  ifstream in("labirent.in");
  in >> R >> C;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      char c; in >> c;
      if(c=='E'){
        cikislar[0][E0] = make_pair(i,j);
        c = '.';
        E0++;
      }
      if(c=='R'){
        robot[0] = make_pair(i,j);
        c = '.'
      }
      if(c=='.') labs[0][i][j] = 1;
      else labs[0][i][j] = 0;
    }
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      char c; in >> c;
      if(c=='E'){
        cikislar[1][E1] = make_pair(i,j);
        c = '.';
        E1++;
      }
      if(c=='R'){
        robot[1] = make_pair(i,j);
        c = '.'
      }
      if(c=='.') labs[1][i][j] = 1;
      else labs[1][i][j] = 0;
    }
  }
}


int main(){
  ofstream out("labirent.out");
  
  input();
}
