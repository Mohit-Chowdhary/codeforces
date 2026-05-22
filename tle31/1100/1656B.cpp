/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    if(n==1){
        if(a[0] == k) cout<<"YES\n"; 
        else cout<<"NO\n";
        return;
    }
    else{
        int i=0, j=1;

        while(i<n && j<n){
            if(a[i] + k == a[j]){
                cout<<"YES\n";
                return;
            }
            else if(a[i] + k < a[j]){
                i++;
            }
            else j++;
        }
    }
    cout<<"NO\n";
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
