#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    ll n,k,b,s;
    cin>>n>>k>>b>>s;

    if(s/k < b){
        cout<<"-1\n";
        return;
    }

    ll maxTaken = min( (b+1)*k-1, s);

    if( (s-maxTaken) > (n-1)*(k-1)){
        cout<<"-1\n";
        return;
    }
    else{
        cout<<maxTaken<<" ";
        ll rest = (s-maxTaken);
        for(int i=1;i<n;i++){
            ll sols = min(k-1,rest);
            cout<<sols<<" ";
            rest -= sols;
        }
        cout<<"\n";
        return;
    }
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
