#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].first;
        a[i].second = i;
    }

    vector<pair<int,int>> b = a;
    sort(b.begin(),b.end());

    vector<int> ans(n);

    int val = 1;
    for(int i=n-1; i>=0;i-=2){
        ans[ b[i].second ] = val;
        val+=1;
    }
    val = -1;
    for(int i=n-2; i>=0;i-=2){
        ans[ b[i].second ] = val;
        val-=1;
    }

    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += 1LL*abs(ans[i]) * a[i].first * 2LL;
    }

    cout<<sum<<"\n0 ";

    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
