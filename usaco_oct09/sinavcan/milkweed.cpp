/*
PROG: milkweed
LANG: C++
ID: kuzux921
*/
#include<fstream>

#define GRASS '.'
#define ROCK '*'
#define WEED 'W'

using namespace std;

char field[100][100];
char next[100][100];
int W, H, ngrass;

void control(int i, int j){
  if(i&&field[i-1][j]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(j&&field[i][j-1]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(i&&j&&field[i-1][j-1]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(i!=H-1&&field[i+1][j]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(j!=W-1&&field[i][j+1]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(i!=H-1&&j!=W-1&&field[i+1][j+1]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(i&&j!=W-1&&field[i-1][j+1]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
  else if(j&&i!=H-1&&field[i+1][j-1]==WEED){
    next[i][j] = WEED;
    ngrass--;
  }
}

void nextweek(){
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      field[i][j] = next[i][j];
}

int main(){
  ifstream in("milkweed.in");
  ofstream out("milkweed.out");
  
  int sx, sy;
  in >> W >> H >> sx >> sy;
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      in >> next[i][j];
      if(next[i][j]==GRASS) ngrass++;
    }
  }
  ngrass--;
  next[H-sy][sx-1]=WEED;
  int week;
  nextweek();
  
  for(week=0;;week++){
    if(ngrass==0) break;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(field[i][j]!=GRASS) continue;
        control(i,j);
      }
    }
    nextweek();
  }
  
  out << week << endl;
  
  return 0;
}
