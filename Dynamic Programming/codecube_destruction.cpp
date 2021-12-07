#include "bits/stdc++.h"

using namespace std;
const int lim = 5e4+10;
typedef long long int lli;
const lli inf = 1e14;
int arr[lim] = {};
lli qs[lim]= {};
lli dp[2][lim];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&k,&m);
    fill(dp[0], dp[0] + n + 1, inf);
    fill(dp[1], dp[1] + n + 1, inf);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&arr[i]);
        qs[i] = lli(arr[i]) + qs[i-1];
    }
    for(int i = 1; i <= k; ++i){
        lli mn = inf;
        for(int j = m ; j <= n ; ++j){ 
            if(i == 1){
                mn = min(mn, -qs[j-m]);
            }else{
                mn = min(mn, 
                     j == m? 
                     -qs[j-m] 
                     : dp[(i-1)%2][j-m-1] - qs[j-m]); 
            }
            dp[i%2][j] = min(dp[i%2][j-1] , mn + qs[j] );
        }
    }
    
    printf("%lld",qs[n] - dp[k%2][n]);
}

