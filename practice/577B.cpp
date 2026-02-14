#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    if(n>m){
        cout<<"YES\n";
        return;
    }

    vector<bool> dp(m,false);

    for(int i=0;i<n;i++){
        int val = a[i]%m;
        vector<bool> new_dp = dp;

        new_dp[val] = true;

        for(int j=0;j<m;j++){
            if(dp[j]){
                new_dp[ (j+val)%m ] = true;
            }
        }
        dp = new_dp;
    }

    if(dp[0]) 
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main(){
    //int tt;
    //cin>>tt;

    //while(tt--){
        solve();
    //}
}
