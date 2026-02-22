#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    ll q = n;
    ll ans;

    for(ll i=2; i*i<=n;i++){
        if(n%i==0){
            q=i;
            break;
        }
    }

    if(q==2) ans = n/2;
    else ans = 1 + (n-q)/2;

    cout<<ans<<"\n";
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
