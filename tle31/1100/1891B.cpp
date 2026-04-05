/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

void solve(){
    int n,q;
    cin>>n>>q;

    vector<ll> a(n);
    vector<ll> b;

    input(a,n);

    int maxVal = 31;

    for(int i=0;i<q;i++){
        ll m;
        cin>>m;
        if(m<maxVal){
            b.push_back(m);
            maxVal = m;
        }
    }

    for(int i=0;i<b.size();i++){
        ll val = 1<<b[i];
        for(int j=0;j<n;j++){
            if(a[j]%val == 0) a[j]+=(val/2);
        }
    }

    output(a);
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
