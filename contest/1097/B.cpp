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
    vector<ll> b;
    vector<ll> unique;
    vector<ll> nonu;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) nonu.push_back(a[i]);
        else unique.push_back(a[i]);
    }
    
    b.push_back(a[n-1]);

    for(auto x: unique) b.push_back(x);
    for(auto x: nonu) b.push_back(x);

    ll ma = 0, mex = 0;
    ll sum = 0;

    vector<bool> seen(n+1,false);

    for(int i=0;i<n;i++){
        ll x = b[i];
        if(x<=n) seen[x] = true;

        while(mex<=n && seen[mex]) mex++;

        sum +=mex + a[n-1];
    }

    cout<<sum<<"\n";
}

int main(){    
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
