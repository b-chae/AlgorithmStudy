#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
  struct node* previous;
  struct node* next;
  int n;
  bool exist;
}node;

node* A[1000000];
int N;
int k;
node* now;
vector<string> cmd;
vector<int> stack;

int main(){

  cin >> N;
  for(int i=0; i<N; i++){
    A[i]->n = i;
    A[i]->exist = true;
  }

  for(int i=0; i<N-1; i++){
    A[i]->next = A[i+1];
  }
  for(int i=1; i<N; i++){
    A[i]->previous = A[i-1];
  }

  A[0]->previous = A[N-1];
  A[N-1]->next = A[0];

  cin >> k;
  now = A[k];

  for(string c:cmd){
    if(c[0] == 'U'){
      int x = atoi(c.substr(2, c.length()-2).c_str());
      while(x>0){
        now = now -> previous;
        x--;
      }
    }
    else if(c[0] == 'D'){
      int x = atoi(c.substr(2, c.length()-2).c_str());
      while(x>0){
        now = now->next;
        x--;
      }
    }
    else if(c[0] == 'C'){
      now->exist = false;
      node* tmp = now->previous;
      tmp->next = now->next;
      node* tmp2 = now->next;
      tmp2->previous = now->previous;
      stack.push_back(now->n);

      if(now->n < now->next->n)
        now = now->next;
      else
        now = now->previous;
    }
    else if(c[0] == 'Z'){
      int a = stack.back();
      stack.pop_back();

      A[a]->exist = true;
      A[a]->previous->next = A[a];
      A[a]->next->previous = A[a];
    }
  }

  string ans = "";
  for(int i=0; i<N; i++){
    if(A[i]->exist) ans += "O";
    else ans += "X";
  }

  return 0;
}
