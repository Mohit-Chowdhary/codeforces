/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<ll> a(n);
    vector<ll> p(n);

    for(int i=0;i<n;i++) cin>>a[i];

    p[0] = a[0];

    for(int i=1;i<n;i++) p[i] = p[i-1]+a[i];
    ll g = 1;


    for(int i=0; i<n-1;i++){
        ll q = gcd(p[i],p[n-1]-p[i]);

        g = max(g,q);
    }

    cout<<g<<"\n";

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
