//SORU 109
//PROGRAM C++

#include <fstream>
#include <list>
#include <queue>
using namespace std;

char map[30][30][30];
int ids[30][30][30];
list<int> adj[2700];

int L, R, C;
int S, E;

void get_ids(){
  int id=0;
  for(int i=0;i<L;i++){
    for(int j=0;j<R;j++){
      for(int k=0;k<C;k++){
        if(!map[i][j][k]) continue;
        if(map[i][j][k]=='S') S = id;
        if(map[i][j][k]=='E') E = id;
        ids[i][j][k] = id;
        id++;
      }
    }
  }
}

void generate_graph(){
  for(int i=0;i<L;i++){
    for(int j=0;j<R;j++){
      for(int k=0;k<C;k++){
        if(!map[i][j][k]) continue;
        if(j!=R-1&&map[i][j+1][k]){
          adj[ids[i][j][k]].push_back(ids[i][j+1][k]);
          adj[ids[i][j+1][k]].push_back(ids[i][j][k]);
        }
        if(k!=C-1&&map[i][j][k+1]){
          adj[ids[i][j][k]].push_back(ids[i][j][k+1]);
          adj[ids[i][j][k+1]].push_back(ids[i][j][k]);
        }
        if(i!=L-1&&map[i+1][j][k]){
          adj[ids[i][j][k]].push_back(ids[i+1][j][k]);
          adj[ids[i+1][j][k]].push_back(ids[i][j][k]);
        }
      }
    }
  }
}

int shortest_path(){
  priority_queue< pair<int, int> > Q;
  Q.push(make_pair(0,S));
  bool visited[2700];

  while(!Q.empty()){
    pair<int, int> curr = Q.top();
    Q.pop();
    if(visited[curr.second]) continue;
    visited[curr.second] = true;

    if(curr.second == E) return -curr.first;

    for(list<int>::iterator it=adj[curr.second].begin();it!=adj[curr.second].end();it++){
      if(visited[*it]) continue;
      Q.push(make_pair(curr.first-1, *it));
    }
  }
  return 0;
}

int main(){
  ofstream out ("dungeon.out");
  ifstream in ("dungeon.in");
  in >> L >> R >> C;
  
  for(int i=0;i<L;i++){
    for(int j=0;j<R;j++){
      for(int k=0;k<C;k++){        
        in >> map[i][j][k];
        if(map[i][j][k]=='#') map[i][j][k]=0;
      }
    }
  }
  
  get_ids();
  generate_graph();
  int res = shortest_path();

  if(res)
    out << "Escaped in " << res << " minute(s)." << endl;
  else
    out << "Trapped!" << endl;

  return 0;
}
