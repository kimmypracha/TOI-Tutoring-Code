#include "bits/stdc++.h"

using namespace std;
const int lim = 1e6+10;
int t[lim];
int n,m;
bool check(int x){
    int cnt = 0;
    for(int i = 0;  i < m ; ++i){
        cnt += x/t[i];
    }
    if(cnt < n){
        return false;
    }
    return true;

}
int main(){
    scanf("%d%d",&m,&n);
    for(int i = 0; i  < m ; ++i){
        scanf("%d",&t[i]);
    }
    // binary search answer

    int l = 0, r = 1e6+10; 
    int mid;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    printf("%d",l);
}