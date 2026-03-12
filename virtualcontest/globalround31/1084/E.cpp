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

int primality(int n){
    
    int p=-1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(p==-1) p = i;
            else return 0;
            while(n%i==0)n/=i;
        }
    }
    
    if(n>1){
        if(p==-1)  p=n;
        else if(p!=n) return 0;
    }

    return p;
}

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    input(a,n);

    int alice_turn = 1;
    int x=1;

    for( x=1;x<n;x++){
        if(a[x-1]>a[x]) break;
    }

    if(x==n){
        cout<<"Bob\n";
        return;
    }

    for(int i=0;i<n;i++){
        if(a[i]==1) continue;
        int p = primality(a[i]);
        if(p == 0){
            cout<<"Alice\n";
            return;
        }
        else{
            a[i] = p;
        }
    }

    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            cout<<"Alice\n";
            return;
        }
    }

    cout<<"Bob\n";


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