#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<vector<pair<int,int>>> paths;

int dx,dy;

void traverse(int i, int j, int x,int y, vector<pair<int,int>>& res){
    if ((dx == 1 && i > x) || (dx == -1 && i < x)) return;
    if ((dy == 1 && j > y) || (dy == -1 && j < y)) return;
    res.push_back({i,j});

    if(i==x && j==y){
        paths.push_back(res);
        res.pop_back();
        return;
    }

    traverse(i+dx,j,x,y,res);

    traverse(i,j+dy,x,y,res);

    res.pop_back();
}

void solve(){
    int i,j,x,y;

    cin>>i>>j>>x>>y;

    dx = x-i<0? -1:1;
    dy = y-j<0? -1:1;

    vector<pair<int,int>> res;
    traverse(i,j,x,y,res);

    for( auto &a: paths){
        cout<<"Path : ";
        for(auto &b: a){
            cout<<b.first<<","<<b.second<<" -> ";
        }
        cout<<"\n";
    }

    int m = abs(x-i);
    int n = abs(y-j);

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int r = 0; r <= n; r++) dp[r][0] = 1;
    for(int c = 0; c <= m; c++) dp[0][c] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            //if(i==j && i==1) continue;

            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }

    cout<<"\n\nTotal number of ways: "<<dp[n][m];
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
        solve();
    //}
}
