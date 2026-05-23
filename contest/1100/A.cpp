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
    vector<ll> a(n);
    int h = INT_MIN, l = INT_MAX;
    for(int i=0;i<n;i++){
        int q; cin>>q;
        h = max(h,q); l = min(l,q);
    }

    int m = (h-l+1);

    cout<<(m/2)<<"\n";
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
