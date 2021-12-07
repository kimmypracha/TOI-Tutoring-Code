#include "bits/stdc++.h"

using namespace std;

const int lim = 6e6+10;
deque<int> dq;
int arr[lim] = {};
int qs[lim] = {};
int dp[lim] = {};
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    for(int i = 1 ; i <= n ; ++i ){
        scanf("%d",&arr[i]);
        qs[i] = arr[i] + qs[i-1];
    }
    int mn_len = w;
    int sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        while(!dq.empty() and dq.front() < i-w) dq.pop_front();
        while(!dq.empty() and qs[dq.back()] > qs[i]) dq.pop_back();
        dq.push_back(i);
        dp[i] = qs[i] -qs[dq.front()];
        if(sum < dp[i]){
            mn_len = i - dq.front();   
        }
        if(sum == dp[i]){
            mn_len = min(mn_len, i-dq.front());
        }
        sum = max(sum, dp[i]);
        
    }
    printf("%d\n%d",sum,mn_len);

}