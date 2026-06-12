/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()


void solve(){
    ll n; cin>>n;

    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    ll ma = *max_element(a.begin(),a.end());
    ll mi = *min_element(a.begin(),a.end());

    cout<<(ma-mi+1)<<"\n";
    
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
