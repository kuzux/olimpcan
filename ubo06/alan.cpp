#include <iostream>
#include <fstream>
using namespace std;

struct dd{
  int x, y, w, h;
};

int N;
dd ddler[5000];
int kesisim[5000][5000];
bool kesisik[5000][5000];
int grup[5000];
int alan[5001];
int currGrup=1;

void read(){
  ifstream in("alan.gir");
  in >> N;

  for(int i=0;i<N;i++)
    in >> ddler[i].x >> ddler[i].y >> ddler[i].w >> ddler[i].h;

  in.close();
}

void kesistir(int i, int j){
  if(i==j) return;
  if(kesisik[i][j]) return;
  if(ddler[i].x+ddler[i].w<=ddler[j].x) return;
  if(ddler[i].y+ddler[i].h<=ddler[j].y) return;
  if(ddler[i].x>=ddler[j].x+ddler[j].w) return;
  if(ddler[i].y>=ddler[j].y+ddler[j].h) return;
  int w, h; 
  if(ddler[i].x<ddler[j].x){
   if(ddler[j].x+ddler[j].w<ddler[i].x+ddler[i].w) w = ddler[j].w;
   else w = ddler[i].x+ddler[i].w-ddler[j].x;
  }
  else{
    if(ddler[i].x+ddler[i].w<ddler[j].x+ddler[j].w) w = ddler[i].w;
    else w = ddler[j].x+ddler[j].w-ddler[i].x;
  }
  if(ddler[i].y<ddler[j].y){
    if(ddler[j].y+ddler[j].h<ddler[i].y+ddler[i].h) h = ddler[j].h;
    else h = ddler[i].y+ddler[i].h-ddler[j].y;
  }
  else{
    if(ddler[i].y+ddler[i].h<ddler[j].y+ddler[j].h) h = ddler[i].h;
    else h = ddler[j].y+ddler[j].h-ddler[i].y;
  }
  kesisim[i][j] = w*h; kesisim[j][i] = w*h; 
  kesisik[i][j] = true; kesisik[j][i] = true;
}

void grupla(int x){
  grup[x] = currGrup;
  alan[currGrup]+=ddler[x].w*ddler[x].h;
  for(int i=0;i<N;i++){
    if(grup[i]) continue;
    if(kesisim[x][i]){
      alan[currGrup]-=kesisim[x][i];
      grupla(i);
    }
  }
}

int Max, MaxCount;
int RGrup;
int ResDdler[5000];

void process(){
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      kesistir(i,j);

  for(int i=0;i<N;i++){
    if(grup[i]) continue;
    grupla(i);
    currGrup++;
  }
  
  for(int i=1;i<=currGrup;i++){
    if(alan[i]>Max){
      Max = alan[i];
      RGrup = i;
    }
  }

  for(int i=0;i<N;i++){
    if(grup[i]==RGrup)
      ResDdler[MaxCount++] = i;
  }
}

void write(){
  ofstream out("alan.cik");
  out << Max << endl;
  out << MaxCount << endl;
  for(int i=0;i<MaxCount-1;i++) out << ResDdler[i]+1 << " ";
  out << ResDdler[MaxCount-1]+1 << endl;
  out.close();
}

int main(){
  read();
  process();
  write();
  return 0;
}

