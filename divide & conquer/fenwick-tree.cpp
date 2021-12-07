#include "bits/stdc++.h"
#define ls(x) (x&(-x)) 
using namespace std;
const int lim = 1e5+10;
int arr[lim];
int ft[lim];
int n;
void build(){
  for(int i = 1; i <= n ; i++){
      for(int j = i; j <= n ; j += ls(j) ){
          ft[j] += arr[i];
      }
  }
}
void update(int idx, int add){
    for(; idx <= n ; idx += ls(idx) ){
        ft[idx] += add;
    }
}
int rsq(int a){
    int sum = 0;
    for(; a; a -= ls(a)){
        sum += ft[a];
    }
    return sum;
}
int rsq(int a, int b){
    return rsq(b)-rsq(a-1);  //a..b
}
int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i ){
        scanf("%d",&arr[i]);
    }
    build();
    int m;
    scanf("%d",&m);
    while(m--){
        int op;
        scanf("%d",&op);
        // 0 = > query
        // 1 => update
        int a,b;
        scanf("%d%d",&a,&b);
        if(op == 0) printf("%d\n", rsq(a,b));
        else update(a,b);
    }
}