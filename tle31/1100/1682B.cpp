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

    vector<int> b = a;

    sort(b.begin(),b.end());

    vector<int> v;

    for(int i=0;i<n;i++){
        if(b[i]!=a[i]) v.push_back(a[i]);
    }
    int s = v[0];

    for(int i=1; i<v.size(); i++){
        s = s & v[i];
    }

    cout<<s<<"\n";
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
