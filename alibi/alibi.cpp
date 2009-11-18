#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
using namespace std;

int dist[500][500];
int pos[100];
int sp[500];
bool visited[500];

int F, P, C, M;

void read(){
  ifstream in("alibi.in");
  in >> F >> P >> C >> M;

  for(int i=0;i<P;i++){
    int a, b, d;
    in >> a >> b >> d; a--; b--;
    dist[a][b] = d;
    dist[b][a] = d;
  }
  for(int i=0;i<C;i++){
    in >> pos[i]; pos[i]--;
  }
  in.close();
}

void shortestpath(int start){
  priority_queue< pair<int, int> > Q;
  Q.push(make_pair(0,start));

  while(!Q.empty()){
    pair<int,int> curr = Q.top(); Q.pop();
    if(visited[curr.second]) continue;
    sp[curr.second] = -curr.first;
    visited[curr.second] = true;

    for(int i=0;i<F;i++){
      if(!dist[curr.second][i]) continue;
      Q.push(make_pair(curr.first-dist[curr.second][i], i));
    }
  }
}

void write(){
  int N=0; 
  for(int i=0;i<C;i++) if(sp[pos[i]]<=M) N++;
  ofstream out("alibi.out");
  out << N << endl;
  for(int i=0;i<C;i++) if(sp[pos[i]]<=M) out << i+1 << endl;
  out.close();
}

int main(){
  read();
  shortestpath(0);
  write();
  return 0;
}

