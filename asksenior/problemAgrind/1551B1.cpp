#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;

    vector<int> m(26,0);

    for(auto x: s){
        m[x-'a'] +=1;
    }

    int total = 0;

    for(auto x:m){
        total+=min(2,x);
    }

    cout<<(total/2)<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
