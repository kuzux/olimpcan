/*
PROG: lights
LANG: C++
ID: kuzux921
*/
#include <fstream>
#include <queue>
#include <list>
#include <bitset>
using namespace std;

struct State{
  int level;
  int next;
  bitset<35> lights;
  bitset<35> switched;
};

int N, M;
list<int> switches[35];

int bfs(){
  queue<State> Q;

  for(int i=0;i<N;i++){
    State s;
    s.level = 1;
    s.next = i;
    Q.push(s);
  }

  while(!Q.empty()){
    State curr = Q.front();
    Q.pop();
    curr.switched[curr.next] = true;
    if(curr.level>N) return -1;
    for(list<int>::iterator it = switches[curr.next].begin();it!=switches[curr.next].end();it++){
      if(curr.lights[*it]) curr.lights[*it] = false;
      else curr.lights[*it] = true;
    }
    if(curr.lights.count()==N)
      return curr.level;
    
    for(int i=0;i<N;i++){
      if(curr.switched[i]) continue;
      curr.next = i;
      curr.level++;
      Q.push(curr);
      curr.level--;
    }
  }
}

int main(){
  ifstream in("lights.in");
  ofstream out("lights.out");

  in >> N >> M;

  for(int i=0;i<N;i++)
    switches[i].push_back(i);
  

  for(int i=0;i<M;i++){
    int a, b; in >> a >> b;
    a--; b--;
    switches[a].push_back(b);
  }

  out << bfs() << endl;
}
