#include <bits/stdc++.h>

using namespace std;
 // All pair - shortest path 
 // O(V^3) V ~ 500
 int G[1000][1000];
 const int inf = 1e8;
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i =0 ; i< m; ++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        G[a][b] = G[b][a] = w;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(G[i][j] == 0) G[i][j] = inf;
        }
    }
    for(int i = 1 ; i <= n ; ++i ){
        for(int j = 1 ; j <= n ; ++j){
            for(int k = 1 ; k <= n ; ++k){
                if(G[j][k] == inf )continue;
                if(j==i or i == k or j == k) continue;
                G[j][k] = min(G[j][i] + G[i][k], G[j][k]);
            }
        }
    }
}