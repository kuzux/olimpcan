//SORU 1176
//PROGRAM C++

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define BOS '.'
#define ENGEL '*'
#define INEK 'C'

struct st{
  int i;
  int j;
  int d;
};

char mat[100][100];
int dist[100][100];
int W, H;
int Cx, Cy;
bool visited[100][100];

void read(){
  ifstream in("lphone.in");
  in >> W >> H;

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      in >> mat[i][j];
      if(mat[i][j]==INEK){ Cx = j; Cy = i; }
    }
  }
}

void write(int res){
  ofstream out("lphone.out");
  out << res << endl;
  out.close();
}

void bfs(int y,int x){
  queue<st> Q;
  st init; init.i = y; init.j = x; init.d = 0;
  Q.push(init);

  while(!Q.empty()){
    st curr = Q.front();
    Q.pop();
    if(visited[curr.i][curr.j]) continue;
    if(curr.d && mat[curr.i][curr.j]==INEK){
      write(curr.d-1);
      return;
    }
    visited[curr.i][curr.j] = true;
    dist[curr.i][curr.j] = curr.d;
    for(int i=curr.i+1;i<H;i++){
      if(mat[i][curr.j]==ENGEL) break;
      st next; next.i = i; next.j = curr.j; next.d = curr.d+1;
      Q.push(next);
    }
    for(int i=curr.i-1;i>=0;i--){
      if(mat[i][curr.j]==ENGEL) break;
      st next; next.i = i; next.j = curr.j; next.d = curr.d+1;
      Q.push(next);
    }
    for(int j=curr.j+1;j<W;j++){
      if(mat[curr.i][j]==ENGEL) break;
      st next; next.i = curr.i; next.j = j; next.d = curr.d+1;
      Q.push(next);
    }
    for(int j=curr.j-1;j>=0;j--){
      if(mat[curr.i][j]==ENGEL) break;
      st next; next.i = curr.i; next.j = j; next.d = curr.d+1;
      Q.push(next);
    }
  }
}

int main(){
  read();
  bfs(Cy, Cx);
  return 0;
}

