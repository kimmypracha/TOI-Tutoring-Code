#include <bits/stdc++.h>

using namespace std;
struct node{
    int a,b,w;
    bool operator < (const struct node& x){
        return w  > x.w;
    }
};
node arr[1010];
bool comp(struct node x, struct node y){
    return x.w > y.w;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n;  ++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        arr[i].a = a;
        arr[i].b = b;
        arr[i].w = w;
    }
    // sort(arr, arr+n) // if use the bool operator
    sort(arr, arr+n, comp); // if use the comp function
}