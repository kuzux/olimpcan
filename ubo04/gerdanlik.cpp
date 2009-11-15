#include <fstream>
#include <list>
#include <climits>
using namespace std;

int N, edges[1000000][2], dyn[1000000][2], weight[1000000];
list<int> adj[1000000];

inline int abs(int x){ return (x<0)?-x:x; }

void read(){
  ifstream in("gerdanlik.inp");
  in >> N;
  for(int i=0;i<N;i++)
    in >> weight[i];
  for(int i=0;i<N-1;i++){
    int a, b; in >> a >> b; a--; b--;
    edges[i][0] = a; edges[i][1] = b;
    adj[a].push_back(i);
    adj[b].push_back(i);
  }
  in.close();
}

void calcWeight(int id){
  if(dyn[id][0]&&dyn[id][1]) return;
  dyn[id][0] = weight[edges[id][0]];
  dyn[id][1] = weight[edges[id][1]];
  for(int i=0;i<2;i++){
    for(list<int>::iterator it=adj[edges[id][i]].begin();it!=adj[edges[id][i]].end();it++){
      if(*it==id) continue;
      calcWeight(*it);
      if(edges[id][i]==edges[*it][0]) dyn[id][i] += dyn[*it][1];
      else dyn[id][i] += dyn[*it][0];
    }
  }
}

void write(int min, int res[]){
  ofstream out("gerdanlik.out");
  out << min << " " << res[0] << " " << res[1] << endl;
  out.close();
}

void process(){
  int min=INT_MAX, res[2];
  for(int i=0;i<N-1;i++){
    calcWeight(i);
    int diff = abs(dyn[i][0]-dyn[i][1]);
    if(diff<min){
      min = diff;
      res[0] = edges[i][0]+1;
      res[1] = edges[i][1]+1;
    }
  }
  write(min, res);
}

int main(){
  read();
  process();
  return 0;
}

