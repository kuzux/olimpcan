/*
PROG: heatwv
LANG: C++
ID: kuzux921
*/
#include <fstream>
#include <climits>
using namespace std;

int N, C;
int **mat;
int dist[2500];
bool visited[2500];

void shortest(int start, int dest){
  for(int i=0;i<N;i++) dist[i] = INT_MAX;
  dist[start] = 0;
  
  for(int i=0;i<N;i++){
    int selected, mindist = INT_MAX;
    for(int j=0;j<N;j++){
      if(visited[j]) continue;
      if(dist[j]<mindist){
        mindist = dist[j];
        selected = j;
      }
    }
    if(selected==dest) return;
    visited[selected] = true;
    for(int j=0;j<N;j++){
      if(mat[selected][j]){
        if(dist[selected]+mat[selected][j]<dist[j])
          dist[j] = dist[selected]+mat[selected][j];
      }
    }
  }
}

int main(){
  ifstream in("heatwv.in");
  ofstream out("heatwv.out");

  int start, end;
  in >> N >> C >> start >> end;

  mat = new int*[N];
  for(int i=0;i<N;i++) mat[i] = new int[N];

  start--; end--;
  for(int i=0;i<C;i++){
    int b, e, l; in >> b >> e >> l;
    b--;e--;
    if(mat[b][e]){
      if(l<mat[b][e]) mat[b][e] = mat[e][b] = l;
    }
    else mat[b][e] = mat[e][b] = l;
  }
  
  shortest(start, end);
  out << dist[end] << endl;
  
  return 0;
}
