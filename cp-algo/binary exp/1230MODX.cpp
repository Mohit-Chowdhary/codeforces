/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll a,n,m;
    cin>>a>>n>>m;
    
    a%=m;
    ll res = 1;

    while(n>0){
        if(n&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        n>>=1;
    }

    cout<<res<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
