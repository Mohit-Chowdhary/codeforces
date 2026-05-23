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
    for(int i=0;i<n;i++) cin>>a[i];

    vector<bool> b(n);

    for(int i=0;i<n;i++){
        if(a[i]>0) b[i] = true;
        else b[i] = false;
    }

    int i = n-1;

    bool shdntbe = true;

    int count = 0;

    vector<int> ans;

    while(i>=0){
        if(b[i] == shdntbe){
            ans.push_back(i+1);
            shdntbe ^= 1;
            count++;
        }
        i--;
    }

    cout<<count<<"\n";

    for(auto x: ans) cout<<x<<" ";
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
