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
    int n,m;
    cin>>n>>m;
    int cur = n;
    int step = 1;
    int dist = 0;
    while(true){
        int next = n+step;

        if((step>0 && next>=m && m>=n) || (step<0 && next<=m && m<=n)){
            dist += abs(m-cur);
            break;
        }
        dist += abs(next-cur);
        cur = next;
        step*=-2;
    }
    cout<<dist<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    while(tt--){
        solve();
    }
}
