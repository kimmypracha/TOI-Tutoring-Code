#include "bits/stdc++.h"

using namespace std;

const int lim = 1e5+10;
int arr[lim];
int seg[4*lim];
int n;
void build(int p = 1, int l = 0 , int r = n-1){
    if(l > r) return;
    if(l == r){
        seg[p] = arr[l];
    }else{
        int mid = (l+r)/2;
        build(p*2, l , mid);
        build(p*2+1, mid+1 , r);
        seg[p] = min(seg[p*2], seg[p*2+1]);

    }
}

int rmq(int a, int b, int p = 1, int l = 0, int r = n-1){
    // printf("%d %d\n",l,r);
    if(l > b || r < a) return 1e9;
    if(a<=l && r <= b){
        return seg[p];
    }else{
        int mid = (l+r)/2;
        int p1 = rmq(a,b, p*2, l, mid);
        int p2 = rmq(a,b, p*2+1, mid+1, r);
        return min(p1,p2);
    }
}

void update(int idx, int val, int p = 1, int l = 0, int r = n-1){
    if(l > idx || r < idx) return;
    if(l == r){
        seg[p] = arr[idx] = val;
    }else{
        int mid = (l+r)/2;
        update(idx, val, p*2, l, mid);
        update(idx, val, p*2+1, mid+1, r);
        seg[p] = min(seg[p*2], seg[p*2+1]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i =0 ;  i < n ; ++i){
        scanf("%d",&arr[i]);
    }
    build(); // O(nlogn)
    int m;
    scanf("%d",&m);
    while(m--){
        int op;
        scanf("%d",&op);
        int a, b;
        scanf("%d%d",&a,&b);
        if(op == 0) printf("%d\n", rmq(a,b));
        else update(a,b);
    }
}