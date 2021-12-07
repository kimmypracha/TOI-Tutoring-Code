#include "bits/stdc++.h"

using namespace std;
char A[100];
char B[100];
int dp[2][100] = {};
int main(){
   scanf("%s%s",A+1,B+1);
   int n = strlen(A+1);
   int m = strlen(B+1);
   for(int i = 1 ; i <= n ; ++i){
       for(int j = 1 ; j <= m;  ++j){
           if(A[i] == B[j]){
               dp[i][j] = dp[i-1][j-1] + 1;
           }else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
   }
   printf("%d",dp[n][m]); 
}
