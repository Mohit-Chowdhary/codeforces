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

    int val = a[n-1];

    int i = n-2;
    int j = 1;
    int changes = 0;

    while(i>=0){
        if(a[i] != val){
            changes++;
            i -= (n-i-1);
        }
        else i--;
    }

    cout<<changes<<"\n";
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
