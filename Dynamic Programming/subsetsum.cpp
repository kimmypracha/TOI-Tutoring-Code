#include "bits/stdc++.h"

using namespace std;
const int lim = 1e3+10;
int arr[lim];
int n,m;
int dp[lim][lim] = {}; // -30000 => 30000 // O(Wn)
const int mid = 30000;
void recur(int x, int idx){
    if(dp[x][idx] > 0 ) return; 
    dp[x][idx] = 1;
    if(idx == n) return;
    recur(x+arr[idx], idx+1);
    recur(x , idx+1);
}
int main(){
    
    scanf("%d%d",&n,&m);
    for(int i = 0; i  < n;  ++i){
        scanf("%d",&arr[i]);
    }
    recur(0, 0);
    if(dp[m][n] > 0){
        printf("Can!!");
    }else{
        printf("Cannot!!!");
    }
}