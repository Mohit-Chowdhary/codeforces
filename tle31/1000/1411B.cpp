/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    for(int i=0;i<2520;i++){
        ll n1 = n+i;
        bool valid = true;

        while(n1>0){
            int d = n1%10;
            if( d!=0 && (n+i)%d ) valid = false;
            n1/=10;
        }

        if(valid){
            cout<<n+i<<"\n";
            return;
        } 
    }
    cout<<"wat";
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
