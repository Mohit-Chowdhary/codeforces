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

    string s;
    cin>>s;

    for(int i=0;i<k;i++){
        int times = 0;

        for(int j = i; j<n; j+=k){
            times ^=s[j]=='1'?1:0;
            //cout<<s[j]<<" ";
        }
        //cout<<endl;

        if(times){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
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
