//SORU 443
//PROGRAM C++
#include <fstream>
using namespace std;

int N;
int dyn[1000000];

int main(){
  ifstream in("sumset.in");
  in >> N;
  in.close();
  
  dyn[0] = 1;

  for(int p=1;p<=20&&p<=N;p*=2){
    for(int i=p;i<=N;i++){
      dyn[i]+=dyn[i-p];
      dyn[i]%=1000000000;
    }
  }

  ofstream out("sumset.out");
  out << dyn[N] << endl;
  out.close();
  return 0;
}
