/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    ll n,l,r;

    cin>>n>>l>>r;

    vector<ll> a(n+1);

    for(ll i=1;i<=n;i++){
        a[i] = (l-1)/i +1;
        a[i]*= i;
        if(a[i]>r){
            cout<<"NO\n"; return;
        }
    }

    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
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
