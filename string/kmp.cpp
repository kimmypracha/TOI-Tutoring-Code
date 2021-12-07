#include "bits/stdc++.h"

using namespace std;
const int lim = 1e5;
int lps[lim] = {};
int main(){
    string T,P;
    cin >> T >> P;
    int j = 0 ; 
    // a b a b a c a
    for(int i = 1 ; i < P.size() ;  ++i){
        while(j != 0 && P[i] != P[j]) j = P[j-1];
        if(P[i] == P[j]){
            j++;
        }else{
            j = 0;
        }
        lps[i] = j;
    }
    j = 0 ;
    bool found = false;
    for(int i = 0 ; i  < T.size() ; ){
        if(T[i] == P[j]){
            i++; j++; // A[0...i-1] = B[0...j-1] 
            if(j == P.size()){
                printf("Found at i = %d to i = %d\n",i-P.size(),i-1);
                found = true;
                j = lps[j-1];
            }
        }else if(j > 0){
            j = lps[j-1];
        }else{
            i++;
        }
    }
    if(not found )printf("Not Found");
}