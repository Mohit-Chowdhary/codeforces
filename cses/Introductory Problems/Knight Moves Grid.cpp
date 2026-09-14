/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;

void solve(){
    int n;
    cin>>n;

    vector<vector<int>> a(n,vector<int>(n,INT_MAX));;
    a[0][0] = 0;

    int dx[] = {1,1,-1,-1,2,2,-2,-2};
    int dy[] = {2,-2,2,-2,1,-1,1,-1};

    //priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    queue<vector<int>> q;
    q.push({0,0,0});

    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int cnt = x[0];
        int i = x[1];
        int j = x[2];
        //if(a[i][j]<=cnt) continue;

        for(int p=0; p<8; p++){
            int ni = i+dx[p];
            int nj = j+dy[p];

            if(ni<0 || nj<0 || ni>=n || nj>=n) continue;
            if(a[ni][nj]!=INT_MAX) continue;
            a[ni][nj] = cnt+1;

            q.push({cnt+1,ni,nj});
        }
    }

    for(auto &x: a){
        for(auto &y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;

    while(tt--){
        solve();
    }
}
