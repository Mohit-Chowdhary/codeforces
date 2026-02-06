#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
    ll n;
    cin>>n;

    while(n>1){
        if(n&1){
            cout<<"YES\n";
            return;
        }
        n>>=1;
    }
    cout<<"NO\n";
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }

}
