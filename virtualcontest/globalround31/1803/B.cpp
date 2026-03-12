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
    int n;
    cin>>n;

    vector<int> primes;
    int p = 1;


    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            p*=i;
            while(n%i==0) n/=i;
        }
    }

    p*=n;

    cout<<p<<"\n";
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