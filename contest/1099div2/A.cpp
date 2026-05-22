/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    ll n;
    cin>>n;
    ll a = n;
    ll n1 = n*2;
    int i = 0;
    while(i<n){
        cout<<n1<<" ";
        i++;
        if(i<n) cout<<n<<" ";
        n1--; n--;
    }
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
