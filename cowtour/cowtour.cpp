#include <fstream>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct point{
  int x;
  int y;
};

int N;
int dist[150][150]; //uzakligin karesi
int fields[150];
int diameter[150];
int fieldDiameter[151];
point pos[150];

inline int point_dist(int a, int b){
  int yd = pos[a].y-pos[b].y, xd = pos[a].x-pos[b].x;
  return xd*xd+yd*yd;
}

void read(){
  ifstream in("cowtour.in");
  in >> N;
  for(int i=0;i<N;i++)
    in >> pos[i].x >> pos[i].y;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      char adj; in >> adj;
      if(adj=='1')
        dist[i][j] = point_dist(i,j);
      else
        dist[i][j] = -1;
    }
  }

  in.close();
}

void shortestpath(){
  //All-pairs shortest path
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        int newd = dist[i][k]+dist[k][j];
        if(dist[i][k]==-1||dist[j][j]==-1) newd = INT_MAX;
        dist[i][j] = min(dist[i][j], newd);
      }
    }
  }
}

int CurrField = 1;

void fill(int i){
  if(fields[i]) return;
  fields[i] = CurrField;
  for(int j=0;j<N;j++)
    if(dist[i][j]!=-1)
      fill(j);
}

void findfields(){
  for(int i=0;i<N;i++){
    if(!fields[i]){
      fill(i);
      CurrField++;
    }
  }
}

void finddiameters(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(diameter[i]<dist[i][j]) diameter[i] = dist[i][j];
      if(diameter[i]<fieldDiameter[fields[i]]) fieldDiameter[fields[i]] = diameter[i];
    }
  }
}

int Res;
void findpath(){
  Res = INT_MAX;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(field[i]==field[j]) continue;
      //(x+y+z)^2 = x^2+y^2+z^2+2xy+2xz+2yz
      int newdiameter = diam[i]*diam[i]+diam[j]*diam[j]+
    }
  }
}

int main(){
  read();
  shortestpath();
  findfields();
  finddiameters();
  findpath();

  return 0;
}
