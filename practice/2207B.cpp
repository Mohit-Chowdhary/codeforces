/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,m,l;
    cin>>n>>m>>l;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    multiset<int> s;
    for(int i=0;i<min(n+1,m);i++){
        s.insert(0);
    }

    int res = l;
    int left = n;
    int idx = 0;
    for(int i=1;i<=l;i++){
        auto it = s.begin();
        int val = (*it)+1;
        s.erase(it);
        s.insert(val);
        if(idx<n && a[idx]==i){
            auto it = prev(s.end());
            int val = *it;
            s.erase(it);
            res-=val;
            if(int(s.size())<left) s.insert(0);
            left--;
            idx++;
        }
    }

    cout<<res<<"\n";
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
