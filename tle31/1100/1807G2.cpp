/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    ll sum = a[0];

    if(sum!=1){
        cout<<"NO\n"; return;
    }

    for(int i=1; i<n;i++){
        if(sum<a[i]){
            cout<<"NO\n"; return;
        }
        sum+=a[i];
    }

    cout<<"YES\n";
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
