#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n,x;
    cin>>n>>x;
    ll count1 = 0;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll m;
        cin>>m;
        count1 += m/x + ((m/x*x == m)?0:1);
        sum+=m;
    }

    ll lsum = sum/x + ((sum/x *x== sum)?0:1);

    cout<<lsum<<" "<<count1<<"\n";

    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
