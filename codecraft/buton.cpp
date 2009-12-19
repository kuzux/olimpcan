#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

typedef pair<int,int> pii;
list<int> graph[10000];
int basis[10000];
int nodes[10000];
int komsu[10000];
int N,R;

void read(){
  ifstream in("buton.in");
  in >> N;
  for(int i=0;i<N-1;i++){
    int a,b; in >> a >> b;a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    komsu[a]++; komsu[b]++;
  }
}

void topsort(){
  vector<pii> V;
  for(int i=0;i<N;i++)
    V.push_back(make_pair(komsu[i],i));
  sort(V.begin(),V.end());
  for(int  i=0;i<N;i++)
    nodes[i] = V[i].second;
}

void process(){
  topsort();
  bitset<10001> bs;
  for(int i=0;i<N;i++){
    bs.reset();
    for(list<int>::iterator it=graph[nodes[i]].begin();it!=graph[nodes[i]].end();it++)
      bs[basis[*it]] = 1;
    int j;
    for(j=1;j<=10000;j++)
      if(!bs[j]) break;
    basis[nodes[i]] = j;
  }
  for(int i=0;i<N;i++)
    R += basis[i];
}

void write(){
  ofstream out("buton.out");
  out << R << endl;
}

int main(){
  read();
  process();
  write();
  return 0;
}

