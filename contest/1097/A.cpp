/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    ll a[n];

    for(int i=n-1;i>=0;i--){
        cin>>a[i];
    }

    ll b[n];

    b[0] = a[0];

    for(int i=1; i<n;i++){
        b[i] = a[i] + max(0LL, b[i-1]);
    }

    int count = 0;
    for(auto x: b){
        //cout<<x<<" ";
        if(x>0) count++;
    }

    cout<<count<<"\n";

}

int main(){    
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
