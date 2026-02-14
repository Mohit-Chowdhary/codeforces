#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k,q;
    cin>>n>>k>>q;

    vector<bool> a(n,false);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        if(m<=q) a[i] = true;
    }

    vector<int> ans;
    int count = 0;

    for(int i=0;i<n;i++){
        if(a[i]){
            count++;
        }
        else{
            ans.push_back(max(0, count-k+1));
            count = 0;
        }
    }
    ans.push_back(max(0, count-k+1));
    ll sum=0;
    for(auto x: ans){
        sum+= (ll) ((1LL+x)*x)/2LL;
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
