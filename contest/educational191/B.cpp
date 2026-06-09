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

    vector<int> a(4*n);

    for(int i=0;i<n;i++) a[i] = i+1;
    for(int i=0; i<n;i++) a[i+n] = n-i;
    for(int i=0; i<n-1;i++) a[i+2*n] = i+1+1;
    a[3*n-1] = 1;
    a[3*n] = 1;
    for(int i=1; i<n;i++) a[i+3*n] = n-i+1;

    for(auto x: a) cout<<x<<" ";
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
