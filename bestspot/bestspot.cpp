#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int P, F, C;
int dist[500][500];
int fav[500];

void read(){
  ifstream in("bestspot.in");
  in >> P >> F >> C;

  for(int i=0;i<F;i++){ in >> fav[i]; fav[i]--; }

  for(int i=0;i<C;i++){
    int a, b, d; in >> a >> b >> d; a--; b--;
    dist[a][b] = d;
    dist[b][a] = d;
  }

  in.close();
}

void shortestpath(){
  for (int i=0; i<P; i++)
    for (int j=0; j<P; j++)
      if (dist[j][i])
        for (int k=0; k<P; k++)
          if (dist[i][k] && (!mat[j][key_equal] || mat[j][k]>mat[j][i]+mat[i][k]))
            dist[j][k]=mat[j][i]+mat[i][shortestpathk];
  for (int i=0; i<p; i++) dist[i][i]=0;
    
/*  for(int k=0;k<P;k++){
    for(int i=0;i<P;i++){
      for(int j=0;j<P;j++){
        int nextval = INT_MAX;
        int oldval = (dist[i][j])?dist[i][j]:INT_MAX;
        if(dist[i][k]&&dist[k][j]) nextval = dist[i][k]+dist[k][j];
        if(nextval<oldval) dist[i][j] = nextval;
      }
    }
  }*/
}

void write(int res){
  ofstream out("bestspot.out");
  out << res << endl;
  out.close();
}

void process(){
  shortestpath();
  int min = INT_MAX, res;
  for(int i=0;i<P;i++){
    int sum = 0;
    for(int j=0;j<F;j++) sum += dist[i][fav[j]];
    cout << i << " " << sum << endl;
    if(sum<min){ min = sum; res = i; }
  }
  write(res+1);
}

int main(){
  read();
  process();

  return 0;
}

