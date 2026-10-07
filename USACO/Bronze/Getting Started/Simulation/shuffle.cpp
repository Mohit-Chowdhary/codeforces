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
    vector<int> a(n);
    input(a,n);

    vector<int> cows(n);
    input(cows,n);

    for(int i=0;i<3;i++){
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = cows[a[i]-1];
        }
        cows = ans;
    }
    for(auto &x: cows) cout<<x<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    while(tt--){
        solve();
    }
}
