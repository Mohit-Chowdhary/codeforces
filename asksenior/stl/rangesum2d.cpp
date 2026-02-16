#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> a(n+1,vector<ll>(m+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    vector<vector<ll>> p(n+1,vector<ll>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            p[i][j] += a[i][j]
                        +p[i][j-1]
                        +p[i-1][j]
                        -p[i-1][j-1];
    }

    for(int i=0;i<q;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        ll sum = p[l2][r2] +-p[l2][r1-1] - p[l1-1][r2] + p[l1-1][r1-1];
        cout<<sum<<"\n";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
