#include <iostream>
#include <fstream>
#include <climits>
#include <list>
#include <utility>
using namespace std;

#define TRANSFER(amn, ht, cond) do{ \
  if((amn)==INT_MAX) break; \
  if((cond)){ \
    if((ht)<heights[i][j]){ \
      newamount = (amn)-heights[i][j]+(ht); \
      if(newamount < 0) newamount = 0; \
      if(newamount < amounts[i][j]) amounts[i][j] = newamount; \
    } \
    else if((ht)>heights[i][j]){ \
      newamount = amn+(ht)-heights[i][j]; \
      if(newamount < 0) newamount = 0; \
      if(newamount < amounts[i][j]) amounts[i][j] = newamount; \
    } \
    else{ \
      newamount = amn; \
      if(newamount < amounts[i][j]) amounts[i][j] = newamount; \
    } \
  } \
}while(false)

#define QADD(y,x,cond) do{ \
  if((cond)&&(amounts[(y)][(x)])) Q.push_back(make_pair((y),(x))); \
}while(false)

int N, M;
int heights[500][500];
int amounts[500][500];
int Res;

void read(){
  ifstream in("wod.in");
  in >> N >> M;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      in >> heights[i][j];
  in.close();
}

void process(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(i==0||j==0||i==N-1||j==M-1) amounts[i][j] = 0;
      else amounts[i][j] = INT_MAX;
    }
  }

  list< pair<int, int> > Q; Q.push_back(make_pair(1,1));
  while(!Q.empty()){
    int i=Q.front().first, j=Q.front().second;
    Q.pop_front();
    int init = amounts[i][j];
    int newamount;
    TRANSFER(amounts[i-1][j], heights[i-1][j], i);
    TRANSFER(amounts[i+1][j], heights[i+1][j], i!=N-1);
    TRANSFER(amounts[i][j-1], heights[i][j-1], j);
    TRANSFER(amounts[i][j+1], heights[i][j+1], j!=M-1);
    if(init!=amounts[i][j]){
      QADD(i-1,j,i);
      QADD(i+1,j,i!=N-1);
      QADD(i,j-1,j);
      QADD(i,j+1,j!=M-1);
    }
  }

  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      Res += amounts[i][j];
}

void write(){
  ofstream out("wod.out");
  out << Res << endl;
  out.close();
}

int main(){
  read();
  process();
  write();
  return 0;
}

