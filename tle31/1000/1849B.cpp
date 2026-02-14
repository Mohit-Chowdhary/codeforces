#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        a[i].first = ((m%k==0)?k:m%k);
        a[i].second = i+1;
    }

    stable_sort(a.begin(),a.end(),[](const pair<int,int>&x, const pair<int,int>&y){
        if(x.first != y.first){
            return x.first>y.first;
        }
        return x.second<y.second;
    });

    for(int i=0;i<n;i++){
        cout<<a[i].second<<" ";
    }
    cout<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
