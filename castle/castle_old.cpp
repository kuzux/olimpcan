/* 
ID: kuzux921
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef char module;
inline bool west_wall(module m){
  return 1&m;
}
inline bool north_wall(module m){
  return 2&m;
}
inline bool east_wall(module m){
  return 4&m;
}
inline bool south_wall(module m){
  return 8&m;
}

typedef vector<module> room;

int Width, Height;
module modules[50][50];
ifstream in("castle.in");
ofstream out("castle.out");
bool searched[50][50];
vector<room> rooms;

void find_rooms(){
  for(int i=0;i<Height;i++){
    for(int j=0;j<Width;j++){
      bool found = false;
      
    }
  }
}

int main(){
  in >> Width >> Height;
  for(int i=0;i<Height;i++){
    for(int j=0;j<Width;j++){
      int tmp; in >> tmp;
      modules[i][j] = tmp;
    }
  }
  find_rooms();
}
