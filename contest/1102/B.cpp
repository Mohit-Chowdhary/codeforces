/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    ll n; cin>>n;
    ll rem = n%12;
    if(rem == 10) rem+=12;

    if(n-rem <0){
        cout<<"-1\n";
        return;
    }

    cout<<rem<<" "<<(n - rem)<<"\n";
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
