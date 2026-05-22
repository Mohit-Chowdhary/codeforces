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
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]] = i+1;
    }

    vector<pair<int,int>> pp;

    for( auto &[x,y]: m){
        pp.push_back({x,y});
    }

    ll sum = -1;

    for(auto &x: pp){
        for(auto &y: pp){
            if( gcd(x.first,y.first)==1 ){
                ll s = x.second+y.second;
                sum = max(sum,s);
            }
        }
    }

    cout<<sum<<"\n";
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
