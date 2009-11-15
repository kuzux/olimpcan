#include <fstream>
#include <queue>
#include <list>
using namespace std;

list<int> graph[100];
int komsu[100];
bool visited[100];
int result[100];
int N;
int R;

void sort(){
  priority_queue< pair<int, int> > Q;
  for(int i=0;i<N;i++)
    Q.push(make_pair(-komsu[i], -i));
  
  while(!Q.empty()){
    int curr = -(Q.top().second);
    Q.pop();
    if(visited[curr]) continue;
    visited[curr] = 1;
    for(list<int>::iterator it=graph[curr].begin();it!=graph[curr].end();it++){
      if(visited[*it]) continue;
      result[R] = *it;
      komsu[*it]--;
      Q.push(make_pair(-komsu[*it], -*it));
    }
    R++;
  }
}

int main(){
  ifstream in("prufer.inp");
  ofstream out("prufer.out");
  in >> N;
  for(int i=0;i<N-1;i++){
    int a, b; in >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    komsu[a]++;
    komsu[b]++;
  }

  sort();
  for(int i=0;i<N-2;i++) out << result[i]+1 << " ";
  out << endl;
}

