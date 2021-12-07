#include <bits/stdc++.h>

using namespace std;

struct node{
  int a,b;
};
typedef struct node node;
const int lim = 1e5+10;
node heap[lim];
int len = 0;
void push(node *curr,int size, int x) {
  curr[size] = x;
  while(size != 1 and curr[size] < curr[size/2]){
    swap(curr[size],curr[size/2]);
    size = size/2;
  }
}
int pop(node *curr, int size){
  int now = 1;
  while(now < size){
    if(now*2 > size and now*2+1 > size) break;
    if(now*2 <= size and now*2+1 > size){
      swap(curr[now*2], curr[now]);
      now = now*2;
    }else{
      if(curr[now*2] < curr[now*2+1]){
        swap(curr[now*2], curr[now]);
        now = now*2;
      }else{
        swap(curr[now*2+1], curr[now]);
        now = now*2+1;
      }
    }
  }
  return curr[now];
}


int main(){
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; ++i){
    int x;
    scanf("%d",&x);
    push(x);
  }
  printf("%d",heap[1]);
}