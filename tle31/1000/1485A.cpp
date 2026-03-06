/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll a,b;
    cin>>a>>b;

    ll res = a+1;
    for(int i = ((b<2)?1:0); i<30; i++){
        ll B = b+i;
        ll times = i;
        ll A = a;
        while(A){
            A/=B;
            times++;
        }
        res = min(res,times);
    }

    cout<<res<<"\n";

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
