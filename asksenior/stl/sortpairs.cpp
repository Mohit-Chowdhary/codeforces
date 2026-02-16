#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<pair<string,int>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(), [](pair<string,int>&a, pair<string,int>&b){
        if(a.second!=b.second) {
            return a.second>b.second;
        }
        return a.first<b.first;
    });

    for(auto [x,y]: a){
        cout<<x<<" "<<y<<"\n";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
