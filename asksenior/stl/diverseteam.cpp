#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> ans;
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(m.count(x)==0){
            ans.push_back(i+1);
        }
        m[x]++;
    }

    if(m.size()<k){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
