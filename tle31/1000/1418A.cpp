/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll x,y,k;
    cin>>x>>y>>k;

    x--;
    ll n=1;
    ll times = ((y+1)*k -1 + x - 1)/ x;

    cout<<times+k<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
