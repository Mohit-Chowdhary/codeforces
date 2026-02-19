#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int l,r;
    cin>>l>>r;

    int n = min(l,r)+1;
    int m = max(l,r)-1;

    if(n%2==0) n++;
    if(m%2==0) m--;

    int q = (m+1 - n);
    int sz = q/2 + q%2;

    ll sol = 1LL*(m+n)/2 * sz;
    if(sz<=0) sol = 0;

    cout<<sol<<"\n";
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
