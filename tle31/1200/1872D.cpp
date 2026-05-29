/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;

    ll lcm = (x/gcd(x,y))*y;

    ll minus = n/y;
    ll common = n/lcm;
    ll plus = n/x-1;

    ll q = x;
    ll total = 0;
    minus -=common;
    plus -= common;
    total += (plus+1)*(2*n-plus)/2;
    ll best = minus*(minus+1)/2;
    total -= best;

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
