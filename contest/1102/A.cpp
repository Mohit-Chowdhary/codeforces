/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end(),greater<int>());

    int x = a[0], y = a[1];
    vector<int> ans;

    for(int i=1; i<n;i++){
        ans.push_back(a[i-1]%a[i]);
    }

    for(int i=2; i<n;i++){
        if(a[i] != ans[i-2]){
            cout<<"-1\n"; return;
        }
    }
    cout<<x<<" "<<y<<"\n";
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
