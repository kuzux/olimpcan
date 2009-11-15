//SORU 238
//PROGRAM C++

#include <iostream>
#include <fstream>
using namespace std;

struct Node{
  char name;
  Node* left;
  Node* right;
};

string In, Pre;

Node* find(int pbegin, int ibegin, int len){
  if(!len) return NULL;
  Node* root = new Node;
  root->name = Pre[pbegin];
  if(len==1){
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  int pos=0;
  for(int i=0;i<len;i++){
    if(In[ibegin+i]==Pre[pbegin]){
      pos = i;
      break;
    }
  }
  root->left = find(pbegin+1,ibegin,pos);
  root->right = find(pbegin+pos+1, pbegin+pos+1, len-pos-1);

  return root;
}

void postorder(Node* self, ostream& out){
  if(self->left) postorder(self->left, out);
  if(self->right) postorder(self->right, out);
  out << self->name;
}

int main(){
  ofstream out ("heritage.out");
  ifstream in ("heritage.in");
  
  in >> In >> Pre;

  Node* res = find(0,0,In.length());

  postorder(res, out);
  out << endl;

  return 0;
}
