/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    input(a,n);
    sort(a.begin(),a.end());

    ll sum = 0;
    ll totalsum = 0;

    for(int i=0;i<2*k;i++){
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        totalsum+=a[i];
    }

    ll minsum = sum;

    int j= n-1;
    for(int i=2*k-2; i>=0;i-=2){
        sum -= a[i]; sum -= a[i+1];

        sum+= a[j--];

        minsum = min(minsum,sum);
    }

    cout<<totalsum-minsum<<"\n";
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
