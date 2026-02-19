#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<ll> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    cout<<p[0]<<" ";

    for(int i=1;i<n;i++){
        cout<<p[i]-p[i-1]<<" ";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
        solve();
    //}
}
