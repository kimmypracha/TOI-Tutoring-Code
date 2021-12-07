#include <bits/stdc++.h>

using namespace std;
const int lim = 1e6+10;
int hash[lim]={};
int hash_func(int x){
    x = x*x;
    x = x<<1;
    x /= 5;
    x += x>>2;
    x %=lim;
    return x;
}
// Separate Chaining 
namespace sep_chain{
    vector<int> hash[lim];
    void insert(int x){
        hash[hash_func(x)].push_back(x);
    }
    bool find(int x){
        for(int y : hash[hash_func(x)]){
            if(y == x){
                return true;
            }
        }
        return false;
    }
}
// open_addressing 
namespace open_addr{
    int hash[lim];
    int skip_func(int x){
        return (x+10)%lim; 
    }
    void insert(int x){
        int idx = hash_func(x);
        while(hash[idx] != 0) idx = skip_func(idx); // infinit loop could happen
        hash[idx] = x;
    }
    bool find(int x){
        int idx = hash_func(x);
        while(hash[idx] != 0){
            if(hash[idx] == x){
                return true;
            }
            idx = skip_func(idx);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i <  n;  ++i){
        int x;
        scanf("%d",&x);
        hash[hash_func(x)] = x; 
    }
    int m;
    scanf("%d",&m);
    for(int i = 0 ;  i < m; ++i){
        int x;
        scanf("%d",&x);
        if(hash[hash_func(x)] != 0){
            printf("Found!\n");
        }else{
            printf("Not Found\n");
        }
    }
}