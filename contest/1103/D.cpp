/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()


void solve(){
    ll n,k; cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());

    int currlen = 1;
    vector<int> breaks;
    bool same = true;

    for(int i=1; i<n; i++){
        if(a[i]-a[i-1] > k){
            //cout<<"currlen: "<<currlen<<" at "<<a[i]<<", "<<a[i-1]<<endl;
            if(same && currlen%2==0){
                cout<<"YES\n";
                return;
            }
            currlen = 0;
            breaks.push_back(i);
        }
        if(a[i]!=a[i-1]) same=false;
        else same = true;
        currlen++;
    }
    if(currlen%2==0){
        cout<<"YES\n";
        return;
    }
    breaks.push_back(n);
    int prev = 0;
    for(auto j: breaks){
        int count = 1;
        for(int i=j-1; i>prev ; i--){
            if(a[i] != a[i-1]){
                //cout<<"count: "<<count<<" at "<<a[i]<<", "<<a[i-1]<<endl;
                if(count%2){
                    cout<<"YES\n";
                    return;
                }
            }
            count++;
        }
        prev = j;
    }

    cout<<"NO\n";
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
