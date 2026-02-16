#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;

    unordered_map<char,int> first;
    unordered_map<char,int> second;
    for(auto x: s) second[x]++;

    int ans = second.size();
    for(auto x:s){
        second[x]--;
        if(second[x]==0) second.erase(x);
        first[x]++;
        ans = max((int)(second.size()+first.size()),ans);
    }

    cout<<ans<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
