#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
using namespace std;

inline int abs(int x){
  if(x<0) return -x;
  return x;
}

struct State{
  int priority;
  int i0, j0;
  int i1, j1;
  bool cik0, cik1;
};

bool operator < (const State s1, const State s2){
  return s1.priority > s2.priority;
}

int R, C;
int E0, E1;
bool labs[2][10][10];
pair<int, int> cikislar[2][100];
pair<int, int> robot[2];

State move_east(State s){
  if(!s.cik0&&s.j0!=C&&labs[0][s.i0][s.j0+1]) s.j0++;
  if(!s.cik1&&s.j1&&labs[1][s.i1][s.j1-1]) s.j1--;
  return s;
}

State move_west(State s){
  if(!s.cik0&&s.j0&&labs[0][s.i0][s.j0-1]) s.j0--;
  if(!s.cik1&&s.j1!=C&&labs[1][s.i1][s.j1+1]) s.j1++;
  return s;
}

State move_south(State s){
  if(!s.cik0&&s.i0!=R&&labs[0][s.i0+1][s.j0]) s.i0++;
  if(!s.cik1&&s.i1&&labs[1][s.i1-1][s.j1]) s.i1--;
  return s;
}

State move_north(State s){
  if(!s.cik0&&s.i0&&labs[0][s.i0-1][s.j0]) s.i0--;
  if(!s.cik1&&s.j1!=R&&labs[1][s.i1+1][s.j1]) s.i1++;
  return s;
}

void input(){
  ifstream in("labirent.inp");
  in >> R >> C;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      char c; in >> c;
      if(c=='E'){
        cikislar[0][E0] = make_pair(i,j);
        c = '.';
        E0++;
      }
      if(c=='R'){
        robot[0] = make_pair(i,j);
        c = '.';
      }
      if(c=='.') labs[0][i][j] = 1;
      else labs[0][i][j] = 0;
    }
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      char c; in >> c;
      if(c=='E'){
        cikislar[1][E1] = make_pair(i,j);
        c = '.';
        E1++;
      }
      if(c=='R'){
        robot[1] = make_pair(i,j);
        c = '.';
      }
      if(c=='.') labs[1][i][j] = 1;
      else labs[1][i][j] = 0;
    }
  }
}

inline int dist(int y, int x, int lab){
  int e = lab?E1:E0;
  int res = 1000;
  for(int i=0;i<e;i++){
    int r = abs(y-cikislar[lab][i].first)+abs(x-cikislar[lab][i].second);
    if(r<res) res = r;
  }
  return res;
}

int heuristic(const State s){
  return dist(s.i0, s.j0, 0) + dist(s.i1, s.j1, 1);
}

bool visited[10][10][10][10];
int dists[10][10][10][10];
State prevs[10][10][10][10];
char move[10][10][10][10];

priority_queue<State> Q;

void add_step(State next, State prev, char step){
  int nextdist=dists[prev.i0][prev.j0][prev.i1][prev.j1]+1;

  if(!dists[next.i0][next.j0][next.i1][next.j1]){
    prevs[next.i0][next.j0][next.i1][next.j1] = prev;
    move[next.i0][next.j0][next.i1][next.j1] = step;
    dists[next.i0][next.j0][next.i1][next.j1] = nextdist;
    int h0 = dist(next.i0,next.j0,0);
    if(!(next.cik0&&h0))
      next.cik0 = true;
    int h1 = dist(next.i1,next.j1,1);
    if(!(next.cik1&&h1))
      next.cik1 = true;

    next.priority = nextdist + h0 + h1;
    Q.push(next);
  }
  else if(nextdist<dists[next.i0][next.j0][next.i1][next.j1]){
    prevs[next.i0][next.j0][next.i1][next.j1] = prev;
    dists[next.i0][next.j0][next.i1][next.j1] = nextdist;
    move[next.i0][next.j0][next.i1][next.j1] = step;
  }
}

void a_star(){
  State init;
  init.cik1 = false; init.cik0 = false;
  init.i0 = robot[0].first; init.j0=robot[0].second;
  init.i1 = robot[1].first; init.j1=robot[1].second;
  init.priority = heuristic(init);
  dists[init.i0][init.j0][init.i1][init.j1] = 0;
  
  Q.push(init);

  while(!Q.empty()){
    State curr = Q.top();
    Q.pop();
    cout << curr.i0 << " "<< curr.j0 << " " << curr.i1 << " " << curr.j1 << endl;
    if(curr.cik0&&curr.cik1){
      cout << "ahanda!" << endl;
      return;
    }
    
    visited[curr.i0][curr.j0][curr.i1][curr.j1] = 1;
    State next;
    next = move_east(curr);
    add_step(next, curr,'e');
    next = move_west(curr);
    add_step(next, curr,'w');
    next = move_north(curr);
    add_step(next, curr,'n');
    next = move_south(curr);
    add_step(next, curr,'s');
  }
}

int main(){
  ofstream out("labirent.out");
  
  input();

  a_star();

}
