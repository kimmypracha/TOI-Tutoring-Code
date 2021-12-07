#include <bits/stdc++.h>

using namespace std;
const int lim = 1e5+10;
int arr[lim];
int par[lim];
vector<int> vec, ind;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n;  ++i){   
        scanf("%d",&arr[i]);
    }
    for(int i =0  ; i < n ; ++i){
        if(i == 0 ){
            vec.push_back(arr[i]);
            par[i] = -1;
            ind.push_back(i);
        }else{
            // 1 
            // 1 2
            // 1 2 3
            // 1 2 3 4
            // 1 2 3 4 5
            int idx = upper_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            if(idx == vec.size()){
                vec.push_back(arr[i]);
                par[i] = ind.back()
                ind.push_back(i);
            }else{
                vec[idx] = arr[i];
                par[i] = par[ind[idx]];
                ind[idx] = i;
            }
        }
    }
    printf("%d",vec.size())
    int cur = ind.back();
    while(cur != -1){
        printf("%d ",arr[cur]);
        cur = par[cur];
    }
}