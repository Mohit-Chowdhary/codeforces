#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    map<int,pair<int,int>> m;

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(m[a[i]].first == 0) m[a[i]].first=i+1;
        m[a[i]].second = i+1;
    } 

    for(int i=0;i<n;i++){
        cout<<m[a[i]].second - m[a[i]].first<<" ";
    }
    cout<<"\n";
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
