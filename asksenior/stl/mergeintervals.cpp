#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

    sort(a.begin(),a.end());

    vector<pair<int,int>> ans;

    ans.push_back(a[0]);
    int j=0;

    for(int i=1;i<n;i++){
        //cout<<ans[j].first<<" "<<ans[j].second<<"\n";
        if(ans[j].second >= a[i].first){
            ans[j].second = max(ans[j].second, a[i].second);
        }
        else{
            ans.push_back(a[i]);
            j++;
        }
    }

    for(int i=0;i<=j;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
