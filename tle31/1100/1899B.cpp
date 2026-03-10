/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> isprime(true,150001);
// void seive(){
//     isprime[0] = false;
//     isprime[1] = false;

//     for(int i=2; i*i<=150000;i++){
//         if(isprime[i]){
//             for(int j=i*i; j<=150000; j+=i){
//                 isprime[j] = false;
//             }
//         }
//     }
// }

void solve(){
    int n;
    cin>>n;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<ll> prefix(n+1,0);

    for(int i=1;i<=n;i++){
        prefix[i] = a[i-1]+prefix[i-1];
    }

    ll res = 0;
    for(int i=1; i*i<=n;i++){
        if( n%i==0){
            vector<int> ks = {i,n/i};

            for(auto k: ks){
                ll curr = 0;
                ll least=LLONG_MAX, highest = LLONG_MIN;
                for(int j=0;j<n;j+=k){
                    curr = prefix[j+k]-prefix[j];
                    least = min(least,curr);
                    highest = max(highest,curr);
                }

                res = max(highest-least,res);
            }
        }
    }
    
    cout<<res<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    // seive();

    while(tt--){
        solve();
    }
}
