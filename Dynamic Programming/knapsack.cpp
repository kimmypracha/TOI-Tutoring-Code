#include "bits/stdc++.h"

using namespace std;
const int lim = 1e3+10;

int n,w;
int dp[lim][lim];
int wei[lim]; // weight
int price[lim]; // price
// Top Down
int recur(int bag, int num){
    if(bag == 0 or num == 0) return 0;
    if(dp[bag][num] != -1) return dp[bag][num];
    if(bag >= wei[num-1]){
        dp[bag][num] = max(
            price[num-1] + recur(bag-wei[num-1],num-1),
            recur(bag, num-1)
        );
        return dp[bag][num];
    }else{
        return dp[bag][num] = recur(bag,num-1);
    }
}
int main(){
    scanf("%d%d",&n,&w);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d%d",&wei[i], &price[i]);
    }
    // top down
    for(int i = 0 ;  i <= w ; ++i)for(int j = 1 ; j <= n ; ++j) dp[i][j] = -1; 
    printf("%d\n", recur(w,n));
    // bottom up
    for(int i = 0 ;  i <= n ; ++i)for(int j = 1 ; j <= w ; ++j) dp[i][j] = 0;
    for(int i = 1; i <= n ; ++i){
        for(int j = 0;  j <= w; ++j){
            if(j == 0){
                dp[i][j] = 0;   // dp[num][weight]
            }else if(j >= wei[i-1]){
                dp[i][j] = max(
                    price[i-1] + dp[i-1][j-wei[i-1]],
                    dp[i-1][j]
                );
            }
        }
    }
    int mx = 0;
    for(int i = 0 ; i <= w ; ++i) mx = max(mx, dp[n][i]);
    printf("%d\n",mx);
}