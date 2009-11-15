/* 
ID: kuzux921
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;

int W, H;

char map[201][78];
bitset<3801> graph[3801];
bool visited[3801];

inline int id(int i, int j){
  return i*W+j;
}

void generate_graph(){
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      
      if(map[2*i+2][2*j+1]==' '){ //bottom
        if(i==H-1){
          graph[id(i,j)][3800] = 1;
          graph[3800][id(i,j)] = 1;
        }
        else{
          graph[id(i,j)][id(i+1,j)] = 1;
          graph[id(i+1,j)][id(i,j)] = 1;
        }
      }

      if(map[2*i+1][2*j+2]==' '){ // right
        if(j==W-1){
          graph[id(i,j)][3800] = 1;
          graph[3800][id(i,j)] = 1;
        }
        else{
          graph[id(i,j)][id(i,j+1)] = 1;
          graph[id(i,j+1)][id(i,j)] = 1;
        }
      }

      if(i==0&&map[0][2*j+1]==' '){ //top
        graph[id(i,j)][3800] = 1;
        graph[3800][id(i,j)] = 1;
      }
      if(j==0&&map[2*i+1][0]==' '){ //left
        graph[id(i,j)][3800] = 1;
        graph[3800][id(i,j)] = 1;
      }

    }
  }
}

int shortest_path(int begin){
  priority_queue< pair<int, int> > Q;
  Q.push(make_pair(0, begin));
  int Res = 0;
  while(!Q.empty()){
    pair<int, int> curr = Q.top();
    Q.pop();

    if(visited[curr.second]) continue;
    visited[curr.second] = true;
    if(-curr.first>Res) Res = -curr.first;
    for(int i=0;i<W*H;i++){
      if(visited[i]) continue;
      if(graph[curr.second][i])
        Q.push(make_pair(curr.first-1, i));
    }
  }
  return Res;
}

int main(){
  ofstream out ("maze1.out");
  ifstream in ("maze1.in");

  in >> W >> H;
  in.ignore();

  for(int i=0;i<2*H+1;i++)
    in.getline(map[i], 2*W+2);

  generate_graph();

  int res = shortest_path(3800);
  out << res << endl;

  return 0;
}
