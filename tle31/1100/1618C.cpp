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

    if(n==1){
        cout<<a[0]<<"\n";
        return;
    }

    ll gcd1 = a[0], gcd2 = a[1];

    for(int i=2;i<n;i+=2){
        gcd1 = gcd(gcd1,a[i]);
    }
    for(int i=3;i<n;i+=2){
        gcd2 = gcd(gcd2,a[i]);
    }

    bool first = true, second = true;
    for(int i=0;i<n;i+=2){
        if( gcd(a[i],gcd2) == gcd2){
            first = false; break;
        }
    }
    if(first){
        cout<<gcd2<<"\n";
        return;
    }

    for(int i=1;i<n;i+=2){
        if( gcd(a[i],gcd1) == gcd1){
            second = false; break;
        }
    }

    if(second){
        cout<<gcd1<<"\n";
        return;
    }
    else cout<<"0\n";
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
