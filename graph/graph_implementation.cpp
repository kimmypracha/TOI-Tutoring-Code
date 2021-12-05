#include <bits/stdc++.h>

using namespace std;
int adjMat[100][100];
vector<int> adjList[100]; 
bool vis[100] = {};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; ++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adjMat[a][b] = adjMat[b][a] = 1;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    // BFS = > Queue
    // DFS = > Stack 
    while(!q.empty()){
        int now = q.front();
        vis[now] =true;
        q.pop();
        // adjMat
        for(int i =1 ; i  <= n ; ++i){
            if(adjMat[now][i] == 1 && !vis[i]){
                q.push(i);
            }
        }
        // adjList
        for(int x : adjList[now]){
            if(!vis[i])q.push(x);
        }

    }
}