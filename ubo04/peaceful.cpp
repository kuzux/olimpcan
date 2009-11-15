#include <fstream>
#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

int N, M;

list<int> gicik[16000];
list<int> selected;

typedef list<int>::iterator lit;

void read(){
  ifstream in("peaceful.inp");

  in >> N >> M;
  for(int i=0;i<M;i++){
    int a, b; in >> a >> b; a--;b--;
    gicik[a].push_back(b);
    gicik[b].push_back(a);
  }
}

void write(bool found){
  ofstream out("peaceful.out");
  if(found){
    for(lit it=selected.begin();it!=selected.end();it++)
      out << *it+1 << endl;
  }
  else{
    out << "NIE" << endl;
  }
  out.close();
}

bool poss(int id){
  for(lit it=selected.begin();it!=selected.end();it++)
    for(lit jt=gicik[*it].begin();jt!=gicik[*it].end();jt++)
      if(*jt==id) return false;
  return true;
}

void dfs(int level){
  if(level==N){
    write(true);
    exit(0);
  }
  if(poss(2*level)){
    selected.push_back(2*level);
    dfs(level+1);
    selected.pop_back();
  }
  if(poss(2*level+1)){
    selected.push_back(2*level+1);
    dfs(level+1);
    selected.pop_back();
  }
}

int main(){
  read();
  dfs(0);
  write(false);
  return 0;
}
