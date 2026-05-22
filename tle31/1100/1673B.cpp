/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    string s; cin>>s;

    unordered_map<char,int> m;

    string block = "";
    string tempblock = "";
    for(auto c: s){
        if(!m[c]){
            m[c]++;
            tempblock+=c;
        }
        else{
            m.clear();
            if(block == "") block = tempblock;
            if(tempblock!=block){
                cout<<"NO\n"; return;
            }
            tempblock = c;
            m[c]++;
        }
    }
    if(block == "") block = tempblock;

    for(int i=0;i<tempblock.size();i++){
        if(tempblock[i]!=block[i]){
            cout<<"NO\n"; return;
        }
    }

    cout<<"YES\n";
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
