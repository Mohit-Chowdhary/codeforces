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

    ll curr = 2;

    while(true){
        ll val = a[0]%curr;

        for(int i=1;i<n;i++){
            if(a[i]%curr!=val){
                cout<<curr<<"\n";
                return;
            }
        }
        curr*=2;
    }

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
