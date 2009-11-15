#include <fstream>
#include <list>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

typedef list< pair<int, char> >::iterator lit;

list< pair<int, char> > graph[50];
map<string, int> counts[50];
map<string, int> totals;

int N, M, K;

void read(){
  ifstream in("muze.gir");
  in >> N >> M >> K;
  for(int i=0;i<M;i++){
    int a, b; char c;
    in >> a >> b >> c;
    a--; b--;
    graph[a].push_back(make_pair(b,c));
  }
  in.close();
}

int nodes[50];
void write(pair<string, int> res){
  ofstream out("muze.cik");

  out << res.first << " " << res.second << endl;

  int cnt = 0;
  for(int i=0;i<N;i++){
    if(counts[i][res.first]){
      nodes[i]=counts[i][res.first];
      cnt++;
    }
  }

  out << cnt << endl;
  for(int i=0;i<N;i++){
    if(nodes[i]) out << i+1 << " " << nodes[i] << endl;
  }

  out.close();
}

char currs[6];
void dfs(int start, int curr, int level){
  if(level==K){
    counts[start][currs]++;
    totals[currs]++;
    return;
  }
  for(lit it=graph[curr].begin();it!=graph[curr].end();it++){
    currs[level]=(*it).second;
    dfs(start,(*it).first, level+1);
    currs[level]=0;
  }
}

bool cmp(pair<string,int> s1, pair<string, int> s2){
  return s1.second < s2.second;
}

void process(){
  for(int i=0;i<N;i++)
    dfs(i,i,0);
  
  pair<string,int> res = *max_element(totals.begin(),totals.end(),cmp);
  write(res);
}

int main(){
  read();
  process();
}
