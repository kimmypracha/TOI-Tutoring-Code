#include "bits/stdc++.h"

using namespace std;
const int lim = 1e5+10;
struct node{
    int a, b , w;
    // constructor function 
    node(int x , int y, int z): a(x), b(y), w(z) {};
};
typedef struct node node;
//edge list 
vector<node> edgeList;

bool comp(node A, node B){
    return A.w < B.w;
}
int p[lim];
int findHead(int x){
    if(p[x] == x) return x;
    return p[x] = findHead(p[x]); // path compression 
    // return p[x] = (p[x]==x)? x : findHead(p[x]); Alternative (ternary operator)
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++i) p[i] = i;
    for(int i= 0 ; i < m ; ++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edgeList.push_back(node(a,b,w));
    }
    sort(edgeList.begin(), edgeList.end(),comp);
    int sum = 0 ;
    for(int i = 0 ; i < m;  ++i){
        int a = edgeList[i].a;
        int b = edgeList[i].b;
        int w = edgeList[i].w;
        if(findHead(a) != findHead(b)){
            p[findHead(b)] = findHead(a);
            sum += w;
        }
    }
    printf("%d",sum);
}
