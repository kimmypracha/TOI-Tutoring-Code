#include <bits/stdc++.h>

using namespace std;
int arr[1000];
int tmp[1000];
void mergesort(int l, int r){
    if(r-l+1 == 1) return;
    int m = (l+r)/2;
    mergesort(l, m);
    mergesort(m+1, r);
    int idx = l;
    int i= l,j = m+1;
    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            tmp[idx++] = arr[i];
            ++i;
        }else{
            tmp[idx++] = arr[j];
            ++j;
        }
    }
    while(i <= m) tmp[idx++] = arr[i++];
    while(j <= m) tmp[idx++] = arr[j++];
    for(int i = l ; i <= r  ; ++i){
        arr[i] = tmp[i];
    }

}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i  < n;  ++i){
        scanf("%d",&arr[i]);
    }
    mergesort(0,n-1);
}

