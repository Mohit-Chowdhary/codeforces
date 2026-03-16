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
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    vector<int> b(n);

    input(a,n);
    input(b,n);

    int bmax = b[0];
    int runsum = a[0];
    int amax = runsum + (k-1)*bmax;

    for(int i=1;i<k;i++){
        
        if(i<n){
            runsum += a[i];
            bmax = max(bmax,b[i]);
        }
        
        int sum = runsum + bmax *(k-i-1);

        amax = max(amax,sum);
    }

    cout<<amax<<"\n";
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