#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<pair<ll,vector<ll>>> a(n, {0, vector<ll>(2)});;

    for(int i=0;i<n;i++){
        cin>>a[i].second[0];
        cin>>a[i].second[1];

        a[i].first = a[i].second[0]*a[i].second[0] + a[i].second[1]*a[i].second[1];
    }
    
    ll k;
    cin>>k;

    sort(a.begin(),a.end());

    for(int i=0;i<k;i++){
        cout<<a[i].second[0]<<" "<<a[i].second[1]<<"\n";
    }
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
