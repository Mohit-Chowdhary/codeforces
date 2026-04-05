/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define all(x) x.begin(),x.end()

int sz = 1e6    ;

vector<bool> isprime(sz+1,true);

void seieve(){
    isprime[0] = false;
    isprime[1] = false;

    for(int i=2; i*i<=sz; i++){
        if(isprime[i]){
            for(int j=i*i; j<=sz; j+=i){
                isprime[j] = false;
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    vector<ll> a;
    a.reserve(n);
    a.push_back(1);

    int k = 0;
    ll pp = 1;

    for(ll i = 2; i < sz && a.size() < n; i++){
        if(isprime[i]){
            ll j = pp*i;
            pp = i;
            a.push_back(j);
        }
    }

    // for(ll i=1;i<n;i++){
    //     ll q = i * (i+1);
    //     a.push_back(q);
    // }
    output(a);
    cout<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;
    seieve();

    while(tt--){
        solve();
    }
}
