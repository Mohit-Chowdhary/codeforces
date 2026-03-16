/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

const ll prime_size = 1000000;
void seive();
vector<bool> isprime(prime_size+1,true);

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define input(v,x) for(int i=0;i<x;i++) cin>>v[i];

void solve(){
    ll n;
    cin>>n;

    vector<pair<ll,ll>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a.begin(),a.end());


    vector<ll> res(n,0);

    for(int i=0;i<n;i++){
        auto [x,y] = a[i];
        ll count = 0;

        for(int j=0;j<n;j++){
            if(a[j].second == y) continue;
            if(a[j].first>x){
                break;
            }
            x+=a[j].first;
            count++;
        }
        res[y] = count;
    }

    for(auto x:res) cout<<x<<" ";

    cout<<"\n";

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