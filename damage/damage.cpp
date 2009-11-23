#include <iostream>
#include <fstream>
#include <list>
using namespace std;

list<int> graph[30000];
int P,C,N;
bool unreachable[30000];

void read(){
  ifstream in("damage.in");
  in >> P >> C >> N;

  for(int i=0;i<C;i++){
    int a, b; in >> a >> b; a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i=0;i<N;i++){
    int a; in >> a; a--;
    unreachable[a] = true;
  }

  in.close();
}

void process(){
  
}

int main(){
  read();
  process();

  return 0;
}
