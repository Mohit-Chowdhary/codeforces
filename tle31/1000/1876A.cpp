#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,p;
    cin>>n>>p;

    vector<pair<ll,ll>> ab(n);

    for(int i=0;i<n;i++) cin>>ab[i].first;
    for(int i=0;i<n;i++) cin>>ab[i].second;

    sort(ab.begin(),ab.end(), [](const pair<ll,ll>&a, const pair<ll,ll>&b){
        if(a.second != b.second)
            return a.second<b.second;
        return a.first>b.first;
    });

    ll sum = p;
    ll done = 1;


    for(int i=0;i<n;i++){
        if(ab[i].second < p){
            ll templeft = min(ab[i].first, n-done);
            sum += templeft * ab[i].second;
            done += templeft;
        }
        else break;
    }

    sum+= (n-done)*p;

    cout<<sum<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
