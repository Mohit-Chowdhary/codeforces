/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    vector<int> candidates;

    int v = a[0];
    if(v==1) candidates.push_back(2);
    while(v>=1){
        candidates.push_back(v);
        if(v==1) break;
        if(v%2==1) v++;
        else v/=2;
    }

    auto cost = [](int num, int target)->ll{
        ll ops = 0;
        while(num!=target){
            if(num<target && (num!=(target-1)))  return INT_MAX;
            ops++;
            if(num==1) break;
            if(num % 2 == 1) num++;
            else num /= 2;
            
        }
        return ops;
    };

    ll ans = LLONG_MAX;

    for(int t: candidates){
        ll total = 0;
        for(int i=0;i<n;i++) total+= cost(a[i],t);
        ans = min(ans, total);
    }

    cout<<ans<<"\n";
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
