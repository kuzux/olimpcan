#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct group{
  int min;
  int max;
  int n;
  int startp;
  int endp;
  int id;
};

bool operator==(const group g1, const group g2){
  return g1.id==g2.id;
}

int N;
vector<group> groups;
int orig[500000];
int ac[500001];
int kapa[500001];
int virgul[500000];
int next[500000];

void read(){
  ifstream in("takim.gir");
  in >> N;
  groups.reserve(N);
  for(int i=0;i<N;i++){
    group g; int a;
    in >> a;
    orig[i] = a;
    next[i] = i+1;
    g.min = a; g.max = a; g.n = 1;
    g.startp = i; g.endp = i+1;
    g.id = i;
    groups.push_back(g);
  }
}

void write(){
  ofstream out("takim.cik");
  for(int i=0;i<N;i++){
    for(int j=0;j<kapa[i];j++) out << ")";
    for(int j=0;j<virgul[i];j++) out << ",";
    for(int j=0;j<ac[i];j++) out << "(";
    out << orig[i];
  }
  for(int j=0;j<kapa[N];j++) out << ")";
  out << endl;
  out.close();
}

inline bool ardisik(const group g1, const group g2){
  int minr=min(g1.min,g2.min), maxr=max(g1.max,g2.max);
  return maxr-minr==g1.n+g2.n-1;
}

void process(){
  int S = N;
  while(S!=1){
    for(int i=0;i<N;i=next[i]){
      if(ardisik(groups[i],groups[next[i]])){
        ac[groups[i].startp]++;
        kapa[groups[next[i]].endp]++;
        virgul[groups[i].endp]++;

        groups[i].endp = groups[next[i]].endp;
        groups[i].min = min(groups[i].min,groups[next[i]].min);
        groups[i].max = max(groups[i].max,groups[next[i]].max);
        groups[i].n += groups[next[i]].n;

        next[i] = next[next[i]];
        S--;
      }
    }
  }
  write();
}

int main(){
  read();
  process();
  return 0;
}

