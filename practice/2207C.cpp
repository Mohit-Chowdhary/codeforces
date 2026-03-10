/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n,h;
    cin>>n>>h;

    ll sum = 0;

    vector<ll> a(n,0);
    ll minh = h;
    ll maxh = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<ll> cnt(n,0);

    for(int i=0;i<n;i++){
        ll curr = a[i];
        cnt[i] = h-curr;
        for(int j=i+1;j<n;j++){
            curr = max(curr,a[j]);
            cnt[i] += h-curr;
        }
        curr = a[i];
        for(int j=i-1; j>=0; j--){
            curr = max(curr,a[j]);
            cnt[i] += h-curr;
        }
    }

    ll best =0;

    for(int i=0;i<n;i++){
        ll mx = a[i], arg = i;
        for(int j=i; j<n;j++){
            if(a[j]>mx){
                mx = a[j];
                arg = j;
            }
            best = max(best, cnt[i]+cnt[j] - cnt[arg]);
        }
    }


    cout<<best<<"\n";
    
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
