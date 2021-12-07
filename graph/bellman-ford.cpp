#include <bits/stdc++.h>

using namespace std;
// negative edge
struct edge{
    int a, b, w;
    edge(int x, int y, int z): a(x), b(y), w(z) {};
};
// int max_var(int a1){
//     return a1;
// }
// int max_var(int a1, ...){ // variadic argument 
//     va_list args;
//     va_start()
//     return max(a1, max(...));
// }
vector<edge> elist;
int d[1000];
const int inf = 1e8;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i =0 ;  i < m;  ++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        elist.push_back({a,b,w});
        elist.push_back({b,a,w});
        // elist.emplace_back(a,b,w);
    }   
    fill(d, d + 1000, inf);
    d[1] = 0;
    // Bellman Ford O(VE)
    for(int i = 0 ;  i  < n ;  ++i){
        for(edge x : elist){
            if(d[x.a] + x.w < d[x.b]){
                d[x.b] = d[x.a] + x.w;
            }
        }
    }
    int t;
    scanf("%d",&t);
    printf("%d",d[t]);

}