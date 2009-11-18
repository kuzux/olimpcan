#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int graph[2000][2000];
bool visited[2000];
int parent[2000];

struct st{
  int dist;
  int id;
  int parent;
};

bool operator <(st s1, st s2){
  return s1.dist  > s2.dist;
}

int N, M;
void read(){
  ifstream in("outofhay.in");
  in >> N >> M;
  for(int i=0;i<N;i++){
    int a, b, d; in >> a >> b >> d; a--;b--;
    if(graph[a][b]&&graph[a][b]<d) continue;
    graph[a][b] = d;
    graph[b][a] = d;
  }
  in.close();
}

void mst(int start){
  priority_queue<st> Q;
  st init; init.id = 0; init.dist = 0; init.parent = 0;
  Q.push(init);
  while(!Q.empty()){
    st curr = Q.top(); Q.pop();
    if(visited[curr.id]) continue;
    visited[curr.id] = true;
    parent[curr.id] = curr.parent;
    for(int i=0;i<N;i++){
      if(!graph[curr.id][i]) continue;
      st next; next.id = i; next.dist = graph[curr.id][i]; next.parent = curr.id;
      Q.push(next);
    }
  }
}

int Res;
void process(){
  mst(0);
  for(int i=0;i<N;i++)
    if(graph[i][parent[i]]>Res) Res = graph[i][parent[i]];
}

void write(){
  ofstream out("outofhay.out");
  out << Res << endl;
  out.close();
}

int main(){
  read();
  process();
  write();

  return 0;
}

