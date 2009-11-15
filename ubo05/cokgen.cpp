#include<iostream>
#include<fstream>
using namespace std;

int N;
int noktalar[250][2];
int miktar[2][50000]

void read(){
  ifstream in("cokgen.gir");

  in >> N;
  for(int i=0;i<N;i++){
    in >> noktalar[i][0] >> noktalar[i][1];
    miktar[0][noktalar[i][0]]++;
    miktar[1][noktalar[i][1]]++;
  }

  in.close();
}

int main(){
  read();
}

