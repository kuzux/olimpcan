/* 
ID: kuzux921
PROG: castle
LANG: C++
*/
#include <fstream>

using namespace std;

int castle[50][50];
int room[50][50];
int sizes[2500];

int W, H;

int currRoom;

void rooms(int i, int j){
  static bool visited[50][50];

  if (visited[i][j]) return;
  visited[i][j] = true;

  room[i][j] = currRoom;
  sizes[currRoom]++;

  int module = castle[i][j];
  if (i!=H-1 && !(module&8))
    rooms(i+1,j);
  if (j!=W-1 && !(module&4))
    rooms(i,j+1);
  if (i && !(module&2))
    rooms(i-1,j);
  if (j && !(module&1))
    rooms(i,j-1);
}


int Ri, Rj, Rs;
char Rd;

/*
void maximize(){
  
  for (int j = W-1; j>=0; j--){
    for (int i = 0; i<H; i++){
        if(i!=H-1 && (castle[i][j]&8)){
        if(room[i][j]!=room[i+1][j]){
          if(sizes[room[i][j]]+sizes[room[i+1][j]]>=Rs){
            Ri = i; Rj=j; Rd = 'N';
            Rs = sizes[room[i][j]]+sizes[room[i+1][j]];
          }
        }
      }
      if(j && (castle[i][j]&1)){
        if(room[i][j]!=room[i][j-1]){
          if(sizes[room[i][j]]+sizes[room[i][j-1]]>=Rs){
            Ri = i; Rj=j; Rd = 'E';
            Rs = sizes[room[i][j]]+sizes[room[i][j-1]];
          }
        }
      }
    }
  }
}*/

inline void update(int i, int j, char d, int s){
  Ri = i; Rj = j; Rd = d; Rs = s;
}

void maximize(){
  for (int i = H-1; i >=0 ; i--) {
    for (int j = 0; j < W; j++) {
      if(i && (castle[i][j]&2)){
        int r1 = room[i][j], r2 = room[i-1][j];
        if(r1!=r2){
          if(sizes[r1]+sizes[r2]>Rs)
            update(i,j,'N',sizes[r1]+sizes[r2]);
          else if(sizes[r1]+sizes[r2]==Rs)
            if(j<Rj) update(i,j,'N',sizes[r1]+sizes[r2]);
            else if(j==Rj&&i>Ri) update(i,j,'N',sizes[r1]+sizes[r2]);
        }
      }

      if(j!=W-1&&(castle[i][j]&4)){
        int r1 = room[i][j], r2 = room[i][j+1];
        if(r1!=r2){
          if(sizes[r1]+sizes[r2]>Rs)
            update(i,j,'E',sizes[r1]+sizes[r2]);
          else if(sizes[r1]+sizes[r2]==Rs)
            if(j<Rj) update(i,j,'E',sizes[r1]+sizes[r2]);
            else if(j==Rj&&i>Ri) update(i,j,'N',sizes[r1]+sizes[r2]);
        }
      }
    }
  }

}

int main(){
  ifstream in("castle.in");  
  ofstream out("castle.out");

  in >> W >> H;

  for (int i = 0; i < H; i++) 
    for (int j = 0; j < W; j++) 
      in >> castle[i][j];
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){ 
      rooms(i,j);
      if(sizes[currRoom]) currRoom++;
    }
  }

  int largest = 0;

  for (int i = 0; i < currRoom; i++) {
    if(sizes[i]>largest) largest = sizes[i];
  }
  maximize();


  out << currRoom << endl;
  out << largest << endl;
  out << Rs << endl;
  out << Ri+1 << " " << Rj+1 << " " << Rd << endl;

  return 0;
  
}
