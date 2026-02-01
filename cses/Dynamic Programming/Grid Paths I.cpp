#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int MOD = 1e9+7;
    int n;
    cin>>n;

    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    if(a[0][0]=='.') dp[1][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 && j==1) continue;
            if(a[i-1][j-1] !='*'){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }

    cout<<dp[n][n];

}
