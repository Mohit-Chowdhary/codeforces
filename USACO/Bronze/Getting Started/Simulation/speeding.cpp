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

    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(m);

    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    
    for(int j=0;j<m;j++) cin>>b[j].first>>b[j].second;
    int diff = 0;
    int i = 0, j = 0;
    int remA = a[i].first, remB = b[j].first;
    while(i<n && j<m){
        diff = max(diff, b[j].second-a[i].second);
        int used = min(remA,remB);
        remA -= used;
        remB -= used;
        if(remA == 0){
            i++;
            if(i<n){
                remA = a[i].first;
            }
        }
        if(remB == 0){
            j++;
            if(j<m){
                remB = b[j].first;
            }
        }
        
    }

    cout<<diff<<"\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    while(tt--){
        solve();
    }
}
