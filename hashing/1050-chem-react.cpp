#include "bits/stdc++.h"

using namespace std;
const int lim = 1e5+10;
vector<int> lst[lim];
map<vector<int>, int> mpi;
int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < p ; ++j){
            int x;
            scanf("%d",&x);
            lst[i].push_back(x);
        }
        mpi[lst[i]] = i+1; 
    }
    vector<int> goal;
    for(int i = 0 ; i < p ; ++i){
        int x;
        scanf("%d",&x);
        goal.push_back(x);
    }
    if(mpi.find(goal) != mpi.end()){
        printf("%d\n", mpi[goal]);
        return 0;
    }else{
        for(int i = 0 ; i < n ; ++i){
            vector<int> tmp;
            for(int j = 0 ; j < p ; ++j){
                tmp.push_back(goal[j]-lst[i][j]);
            }
            if(mpi.find(tmp) != mpi.end()){
                printf("%d %d\n", i+1, mpi[tmp]);
                return 0 ;
            }
        }
        printf("NO\n");
    }
}