#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,q;
    cin>>n>>q;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> p(n+1,0);
    
    for(int i=0;i<n;i++){
        p[i+1] += a[i]+p[i];
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<p[r]-p[l-1]<<"\n";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
