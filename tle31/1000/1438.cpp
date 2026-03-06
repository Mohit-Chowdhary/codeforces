/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    set<int> s;
    bool valid = false;

    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        if(s.count(q)){
            valid = true;
        }
        s.insert(q);
    }

    if(valid) cout<<"YES\n";
    else cout<<"NO\n";
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
