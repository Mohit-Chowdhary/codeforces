/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;

bool sgn(ll x){
    if(x>0) return 1;
    return 0;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<int> pos(n,-1);
    vector<ll> cost(n,0);
    for(int i=0;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x>y || x>z || y>z) pos[i]=1;
        else if(x==y && x==z && y==z){
            pos[i]=0;
        }
        else{
            cost[i] = min(y-x+1,z-x+1);
        }
        a[i] = x+y+z;
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
