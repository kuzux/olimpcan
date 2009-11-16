//SORU 500
//PROGRAM C++
#include <fstream>
#include <queue>
#include <utility>
using namespace std;

int N, K;

void read(){
  ifstream in("catchcow.in");
  in >> N >> K;
  in.close();
}

bool visited[100000];
int shortestpath(){
  priority_queue< pair<int,int> > Q;
  Q.push(make_pair(0,N));

  while(!Q.empty()){
    pair<int,int> curr = Q.top();
    Q.pop();
    if(visited[curr.second]) continue;

    if(curr.second==K) return -curr.first;

    if(curr.second!=1) Q.push(make_pair(curr.first-1,curr.second-1));
    if(curr.second<=100000) Q.push(make_pair(curr.first-1,curr.second+1));
    if(curr.second*2<=100000) Q.push(make_pair(curr.first-1,curr.second*2));
  }
}

int main(){
  read();
  int res = shortestpath();
  ofstream out("catchcow.out");
  out << res << endl;
  out.close();
  return 0;
}

