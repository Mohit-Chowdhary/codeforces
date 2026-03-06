/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,m;
    cin>>n>>m;
    ll sum = 0;
    ll zero = 0;
    ll least = INT_MAX;
    ll negatives = 0;

    for(int i=0;i<n*m; i++){
        ll q;
        cin>>q;
        if(q<0){
            q*=-1;
            negatives++;
        } 
        sum+=q;
        if(q==0) zero++;
        least = min(least,q);
    }

    if(negatives%2){
        sum-= 2*least;
    }

    cout<<sum<<"\n";
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
