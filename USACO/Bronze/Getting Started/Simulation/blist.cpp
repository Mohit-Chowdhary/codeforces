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
    vector<pair<int,int>> a;

    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a.push_back({x,z});
        a.push_back({y,-z});
    }

    sort(a.begin(),a.end());

    int sz = 0;
    int best = 0;
    for(auto &[x,y]: a){
        sz+=y;
        best = max(sz,best);
    }

    cout<<best<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    while(tt--){
        solve();
    }
}
