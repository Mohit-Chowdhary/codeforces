/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void back(string s, set<string>& v){
    if(s.size()==1) return;

    string s1 = s[0]+s.substr(2);
    string s2 = s.substr(1);
    v.insert(s1); v.insert(s2);

    back(s1,v);
    back(s2,v);
    
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    set<string> v;

    back(s,v);

    cout<<v.size()+1<<"\n";
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
