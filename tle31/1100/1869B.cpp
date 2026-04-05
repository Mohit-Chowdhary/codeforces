/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];



void solve(){
    int n,k,a,b;

    cin>>n>>k>>a>>b;
    a--; b--;

    vector<pair<ll,ll>> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    ll smallest = llabs(arr[a].first-arr[b].first) + llabs(arr[b].second-arr[a].second);

    ll smal1 = LLONG_MAX/2, smal2 = LLONG_MAX/2;

    if(k<2){
        cout<<smallest<<"\n";
        return;
    }

    for(int i=0;i<k;i++){
        smal1 = min(smal1,llabs(arr[a].first-arr[i].first) + llabs(arr[i].second-arr[a].second));
        smal2 = min(smal2,llabs(arr[i].first-arr[b].first) + llabs(arr[b].second-arr[i].second));
    }

    if(smal1+smal2 < smallest) smallest = smal1+smal2;

    cout<<smallest<<"\n";
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
