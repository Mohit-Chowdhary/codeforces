/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int total = 0;
    int m[26]={0};
    for(int i=0;i<n;i++){
        int x = s[i];
        if(!m[x-'a']){
            total += n-i;
            m[x-'a']++;
        }
    }

    cout<<total<<"\n";
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
