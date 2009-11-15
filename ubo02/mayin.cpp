#include <fstream>
using namespace std;

int N, M, K;
int tarla[20][20];
bool mayin[20][20];

bool solved(){

}

void dfs(int n){
  if(n==K&&solved()) return;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(tarla[i][j]!=-1) continue;
      if(mayin[i][j]) continue;
      mayin[i][j]=true;
      dfs(n+1);
      mayin[i][j]=false;
    }
  }
}

int main(){
  ifstream in("mayin.in");
  ofstream out("mayin.out");
  in >> N >> M >> K;
  
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      in >> tarla[i][j];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(tarla[i][j]!=-1) continue;
      mayin[i][j]=true;
      dfs(0);
      mayin[i][j]=false;
    }
  }
}
