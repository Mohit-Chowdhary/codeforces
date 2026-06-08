/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    ll n,k;
    cin>>n>>k;

    string a,b; cin>>a>>b;
    string  c = "";
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) c+="0";
        else c+="1";
    }
    ll a1 = count(a.begin(),a.end(),'1');
    ll a0 = n-a1;
    
    ll b1 = count(b.begin(),b.end(),'1');
    ll b0 = n-b1;
    ll c1 = count(c.begin(),c.end(),'1');
    ll c0 = n-c1;

    ll all = a0*a1 + b0*b1 + c0*c1;

    ll times = (1<<k) +1;
    //cout<<times<<" ";
    ll total = 0;
    total += (times/3) * all;

    if(times%3) total+= a0*a1 + b0*b1;

    cout<<total<<"\n";

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
