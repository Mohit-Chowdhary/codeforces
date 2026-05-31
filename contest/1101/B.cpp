/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> ans;
    ans.push_back(a[0]);
    ll total = a[0];
    ll best = a[0];
    for(int i=1;i<n;i++){
        if(a[i]<best){
            total+=a[i];
            best = min((total/(i+1)),best);
            ans.push_back(best);
            //cout<<"well "<<best<<" ";
        }
        else{
            ans.push_back(best);
            //cout<<"shell "<<best<<" ";
            total+=a[i];
            best = min(best,total/(i+1));
        }
    }
    for(auto x: ans) cout<<x<<" ";
    cout<<"\n";

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
