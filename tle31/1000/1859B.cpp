#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    ll minel = INT_MAX;

    vector<ll> min1(n);
    vector<ll> min2(n);

    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<ll> a(m);
        for(int j=0;j<m;j++){
            cin>>a[j];
        }
        sort(a.begin(), a.end());
        min1[i] = a[0];
        min2[i] = a[1];
    }

    sort(min1.begin(),min1.end());
    sort(min2.begin(),min2.end());

    ll sum = min1[0];

    for(int i=1;i<n;i++){
        sum+=min2[i];
    }

    cout<<sum<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
