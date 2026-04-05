/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";

void solve(){
    int n;
    cin>>n;

    vector<pair<ll,int>> a(n);

    for(int i=0;i<n;i++){
        a[i].second = i;
        cin>>a[i].first;
    }

    sort(a.begin(), a.end());

    vector<ll> pre(n);

    pre[0]=a[0].first;

    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+a[i].first;
    }

    vector<int> ans(n);

    ans[n-1] = n-1;

    for(int i=n-2;i>=0; i--){
        if(a[i+1].first <= pre[i]){
            ans[i] = ans[i+1];
        }
        else{
            ans[i] = i;
        }
    }

    vector<int> res(n);

    for(int i=0;i<n;i++){
        int og = a[i].second;
        res[og] = ans[i];
    }

    output(res);
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
