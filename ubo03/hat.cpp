#include <fstream>
#include <iostream>
#include <queue>
#include <bitset>
#include <climits>
using namespace std;

int graph[100][100];
bitset<100> tree;
int salla[5];
bitset<100> gec;
int N, K, E;
int Min=INT_MAX;

int mst(){
  priority_queue< pair<int, int> > Q;
  tree.reset();
  for(int i=0;i<N;i++){
    if(!gec[i]){
      Q.push(make_pair(0, i));
      break;
    }
  }

  int Res=0;

  while(!Q.empty()){
    if((gec|tree).count()==N) return Res;
    pair<int, int> curr = Q.top();
    Q.pop();
    tree[curr.second] = 1;
    Res -= curr.first;
    
    for(int i=0;i<N;i++){
      if(tree[i]) continue;
      if(gec[i]) continue;
      if(graph[curr.second][i])
        Q.push(make_pair(-graph[curr.second][i], i));
    }
  }
  return INT_MAX;
}

void dfs(int lvl){
  if(lvl==K){
    int res = mst();
    cout << res << endl;
    if(res<Min) Min = res;
    return;
  }
  dfs(lvl+1);
  gec[salla[lvl]] = 1;
  dfs(lvl+1);
  gec[salla[lvl]] = 0;
}

int main(){
  ifstream in("hat.inp");
  ofstream out("hat.out");

  in >> N >> K;
  for(int i=0;i<K;i++){
    int a; in >> a; a--;
    salla[i] = a;
  }
  in >> E;
  for(int i=0;i<E;i++){
    int a, b, d; in >> a >> b >> d;
    a--; b--;
    graph[a][b] = d;
    graph[b][a] = d;
  } 
  dfs(0);
  out << Min << endl;
}

