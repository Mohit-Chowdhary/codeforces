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
    int n,m; cin>>n>>m;

    vector<vector<char>> a(n,vector<char>(m));

    string search = "ABCD";
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            for(char c: search){
                if(c == s[i][j] || (i>0 && c==a[i-1][j]) || (j>0 && c == a[i][j-1]))  continue; 
                a[i][j] = c;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(auto x: a[i]) cout<<x;
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
