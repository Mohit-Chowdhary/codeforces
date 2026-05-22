/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    ll n;
    cin>>n;

    ll s = n*n;
    s%=MOD; s*=4; s+=3*n; s-=1;
    s%=MOD;
    s*=n;
    s%=MOD;
    s*=337;
    s%=MOD;
    cout<<s<<"\n";
    
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
