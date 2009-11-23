#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <utility>
using namespace std;

list< pair<int,int> > graph[200000];
int N, M;

void read(){
  ifstream in("travel.in");
  in >> N >> M;
  for(int i=0;i<M;i++){
    int a, b, d; in >> a >> b >> d; a--; b--;
    graph[a].push_back(make_pair(b,d));
    graph[b].push_back(make_pair(a,d));
  }

  in.close();
}

void process(){
  
}

int main(){
  read();
  process();
}
