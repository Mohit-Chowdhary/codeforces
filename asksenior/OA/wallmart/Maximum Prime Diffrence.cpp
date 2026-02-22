#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> isprime(100001,true);

void sieve(){
    isprime[0]=false; isprime[1]=false;

    for(int i=2;i*i<100001;i++){
        if(isprime[i]){
            for(int j = i*i; j<100001; j+=i){
                isprime[j] = false;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;

    int earliest = INT_MAX;
    int latest = INT_MIN;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;

        if(isprime[m]){
            earliest = min(earliest,i);
            latest = max(latest,i);
        }
    }

    if(earliest == INT_MAX || latest == INT_MIN){
        cout<<"-1\n";
        return;
    }

    cout<<latest-earliest<<"\n";

}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
