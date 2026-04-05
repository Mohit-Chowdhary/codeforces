/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define all(x) x.begin(),x.end()

void solve(){
    ll mod = 1e9+7;
    ll n;
    cin>>n;

    vector<ll> a(n);
    vector<ll> b(n);

    input(a,n); input(b,n);

    sort(all(a)); sort(all(b));


    ll j=n-1;

    ll total = 1;

    for(ll i=n-1;i>=0;i--){
        while(j>=0 && a[j]>b[i]){
            j--;
        }
        //cout<< i-j<<endl;
        total*= i-j;
        total = total%mod;
        
    }

    cout<<total<<"\n";
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
