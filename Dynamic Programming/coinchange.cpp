#include "bits/stdc++.h"

using namespace std;
int coin[100];
int m;
int dp[1000];
int recur(int n){
    int mn = 1e9;
    if(dp[n] > 0) return dp[n];
    if(n == 0) return 0 ;
    for(int i = 0 ; i  < m; ++i ){
        if(n >= coin[i]){
            mn = min(mn, 1+recur(n-coin[i]));
        }
    }
    return dp[n] = mn;
}
int main(){
    int n;
    scanf("%d%d",&n,&m); // n = the price, m = the number of coin
    for(int i = 0 ; i < m;  ++i){
        scanf("%d",&coin[i]); // assume that it always have 1 baht
    }
    int ans = recur(n);
    printf("%d",ans);
    for(int i = 1 ; i <= n ; ++i){
        dp[i] = 1e9;
        for(int j = 0;  j < m ; ++j){
            if(i >= coin[j]){
                dp[i] = min(dp[i],dp[i-coin[j]]);
            }
        }
    }
}