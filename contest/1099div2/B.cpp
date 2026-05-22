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

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int md = 0;

    for(int i=0; i<n-1;i++){
        if(a[i]>a[i+1]){
            md = max(md,a[i]-a[i+1]);
        }
    }

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            a[i+1] +=md;
        }
    }

    if(is_sorted(a.begin(),a.end())) cout<<"YES\n";
    else cout<<"NO\n";
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
