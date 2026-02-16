#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,q;
    cin>>n>>q;

    set<int> s;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        s.insert(m);
    }

    for(int i=-q;i<=q;i++){
        if(s.count(i)==0){
            cout<<i;
            return;
        }
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
