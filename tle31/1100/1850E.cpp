/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

// ll pow(ll a, ll n){
//     ll res = 1;
//     while(n){
//         if(n&1) res*=a;
//         a*=a;
//         n>>=1;
//     }

//     return res;
// }

void solve(){
    ll n,c;
    cin>>n>>c;

    ll sum = 0;
    ll sqsum = 0;

    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];;

        sum+=a[i];
        //c -= a[i];
    }

    ll l = 0, r = 1e9;

    while(l<=r){
        ll x = l + (r-l)/2;

        ll sumall = 0;

        for(int i =0;i<n;i++){
            sumall += (a[i]+2*x)*(a[i]+2*x);
            if(sumall>c) break;
        }
        if(sumall == c){
            cout<<x<<"\n";
            return;
        }
        else if(sumall > c){
            r = x-1;
        }
        else{
            l = x+1;
        }
    }
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;

    while(tt--){
        solve();
    }
}
