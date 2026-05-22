/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    ll m = LLONG_MAX;
    bool hasNeg = false;
    ll sum = 0;

    for(int i=0;i<n;i++){
        ll q;
        cin>>q;
        if(q<0) hasNeg ^=1;
        m = min(m,abs(q));
        sum+= abs(q);
    }

    if(hasNeg) sum -= 2*m;
    

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
