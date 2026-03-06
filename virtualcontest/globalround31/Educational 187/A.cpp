/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,m,d;
    cin>>n>>m>>d;

    int q = d/m+1;

    int s = n/q + ((n/q * q == n)?0:1);

    cout<<s<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
