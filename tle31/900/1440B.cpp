#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    ll sum = 0;
    
    vector<int> a(n*k);
    for(int i=0; i<n*k;i++) cin>>a[i];

    int j = n*k-1-n/2;
    int m = n/2+1;

    for(int i=0; i<k;i++){
        sum+=a[j];
        j-=m;
    }

    cout<<sum<<"\n";
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
