#include<fstream>
using namespace std;

int N,K;
int dyn[202][102];
int solve(){
  for(int i=1;i<=K;i++)
    dyn[1][i]=1;

  for(int i=2; i<=N; i++){
    for(int j=1; j<=K; j++){
      for(int k=1; k<=i-2; k++){
        dyn[i][j]+=dyn[k][j-1]*dyn[i-k-1][j-1];
        dyn[i][j]%=9901;
      }
    }
  }

  return dyn[N][K]-dyn[N][K-1];
}

int main(){
  ofstream out ("nocows.out");
  ifstream in ("nocows.in");

  in >> N >> K;

  out << (solve()+9901)%9901 << endl;
      
  return 0;
}

