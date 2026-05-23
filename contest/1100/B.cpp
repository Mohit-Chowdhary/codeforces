/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    ll h = LLONG_MIN;
    ll sum = 0;

    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            sum+=a[i];
            h = max(h,b[i]);
        }
        else{
            sum+=b[i];
            h = max(h,a[i]);
        }
    }

    cout<<sum+h<<"\n";
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
