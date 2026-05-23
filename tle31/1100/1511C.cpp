/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> b(m);
    //for(auto x: b) cout<<x<<endl;

    vector<int> val(51,INT_MAX);

    for(int i=0;i<n;i++){
        int q; cin>>q;
        if( val[q] == INT_MAX) val[q] = i+1;
    }
    for(int i=0;i<m;i++) cin>>b[i];

    for(auto &x: b){
        int pos = val[x];
        cout << pos << " ";
        for(auto &y: val)
            if(y < pos) y++;
        val[x] = 1;
    }
    cout<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt;
    //cin>>tt;

    //while(tt--){
        solve();
    //}
}
