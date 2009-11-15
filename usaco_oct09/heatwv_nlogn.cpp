#include <fstream>
#include <utility>
#include <queue>
using namespace std;

int mat[2500][2500];
bool visited[2500];
int N, C;

int shortest(int start, int end){
  priority_queue< pair<int, int> > Q;

  Q.push(make_pair(0,start));


  while(!Q.empty()){
    pair<int, int> curr = Q.top();
    Q.pop();
    if(visited[curr.second]) continue;
    visited[curr.second] = true;
    if(curr.second==end) return curr.first;
    for(int i=0;i<N;i++){
      if (visited[i]) continue;
      if(mat[curr.second][i])
          Q.push(make_pair(curr.first-mat[curr.second][i],i));
    }
  }
  return -1;
}

int main(){
  ifstream in("heatwv.in");
  ofstream out("heatwv.out");
  
  int start, end;
  in >> N >> C >> start >> end;
/*
  mat = new int*[N];
  for(int i=0;i<N;i++) mat[i] = new int[N];
*/
  start--; end--;
  for(int i=0;i<C;i++){
    int b, e, l; in >> b >> e >> l;
    b--;e--;
    if(mat[b][e]){
      if(l<mat[b][e]) mat[b][e] = mat[e][b] = l;
    }
    else mat[b][e] = mat[e][b] = l;
  }
  
  out << -shortest(start, end) << endl;

  return 0;
}
