/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()


void solve(){
    int n; cin>>n;
    int m = n*(n-1)/2;
    vector<int> a(m);
    for(int i=0;i<m ;i++) cin>>a[i];

    sort(a.begin(),a.end());

    for(int i=0;i<m;i+=--n)cout<<a[i]<<" ";
    cout<<a[m-1]<<"\n";
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
