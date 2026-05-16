/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n,en,vi,m;

    cin>>n>>en>>vi>>m;
    if(n==2 || n==3){
        cout<<"1\n";
        return;
    }
    ll sol = m+ min(abs(en-vi), min(en,vi) + n-max(en,vi));
    cout<<sol<<"\n";
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
