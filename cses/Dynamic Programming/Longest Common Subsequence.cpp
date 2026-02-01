#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1; i<=n;i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i = n, j = m;

    vector<int> ans(dp[n][m]);
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans[dp[i][j]-1] = a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout<<dp[n][m]<<"\n";

    for(auto x:ans) cout<<x<<" ";
}
