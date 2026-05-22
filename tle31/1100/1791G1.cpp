/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n,k;

    cin>>n>>k;

    vector<ll> a(n);

    for(int i=0;i<n;i++){
        ll q;
        cin>>q;
        a[i] = q+i+1;
        //cout<<a[i]<<endl;
    }

    sort(a.begin(),a.end());

    ll sum = 0;
    int count = 0;

    for(auto x: a){
        sum+=x;
        if(sum<=k) count++;
        else break;
    }

    cout<<count<<"\n";
    

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
