/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;

    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( a[i][j] != a[n-i-1][n-j-1] ) count++;
        }
    }
    count/=2;

    if(count>k){
        cout<<"NO\n";
    }
    else{
        k-=count;
        if(n&1)cout<<"YES\n";
        else if(k&1) cout<<"NO\n";
        else cout<<"YES\n";
    }

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
