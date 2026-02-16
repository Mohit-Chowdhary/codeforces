#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll w,h;
    cin>>w>>h;

    string line;
    ll miw = INT_MAX;
    ll maw = INT_MIN;
    ll mih = INT_MAX;
    ll mah = INT_MIN;
    ll mw = INT_MIN ; ll mh = INT_MIN;
    for(int i=0;i<2;i++){
        ll x;
        int n;
        cin>>n;
        while(n--){
            cin>>x;
            miw = min(miw,x);
            maw = max(maw,x);
        }
        mw = max(mw,maw-miw);
        miw = INT_MAX; maw = INT_MIN;
    }
    for(int i=0;i<2;i++){
        ll x;
        int n;
        cin>>n;
        while(n--){
            cin>>x;
            mih = min(mih,x);
            mah = max(mah,x);
        }
        mh = max(mh,mah-mih);
        mih = INT_MAX; mah = INT_MIN;
    }


    ll ans = max(mw*h, mh*w);

    cout<<ans<<"\n";
    
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
