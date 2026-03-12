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
    
    vector<int> a(n);
    input(a,n);

    int idx = -1, prev = -1;
    int count = 0;
    int idx1 = -1;


    for(int i=0;i<n;i++){
        if(prev<a[i]){
            prev = a[i];
            idx = i;
        }

        if(prev == i+1){
            count++;
            // if(count>1){
            //     swap(a[i],a[idx1]);
            //     break;
            // }
            // idx1=idx;
        }
    }
    if(count>){
        swap(a[idx],a[0]);
    }

    for(auto x: a) cout<<x<<" ";
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