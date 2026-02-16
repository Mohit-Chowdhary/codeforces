#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,q;
    cin>>n>>q;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<ll> d(n+1);
    d[0] = a[0];
    for(int i=1;i<n;i++) d[i] = a[i]-a[i-1];

    for(int i=0; i<q; i++){
        ll l,r,v;
        cin>>l>>r>>v;

        d[l-1] += v;
        d[r] -= v;
    }

    ll m = 0;

    for(int i=0;i<n;i++){
        m+=d[i];
        cout<<m<<" ";
    }
    cout<<"\n";
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
