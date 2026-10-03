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
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<char>> a(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }

    for(int i=0; i<n; i++){
        for(int q=0; q<k;q++){
            for(int j=0; j<m;j++){
                for(int r=0; r<k;r++) 
                    cout<<a[i][j];
            }
            
        cout<<"\n";
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    while(tt--){
        solve();
    }
}
