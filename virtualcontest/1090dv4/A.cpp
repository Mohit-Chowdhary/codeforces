/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define all(x) x.begin(),x.end()

void solve(){
    ll sum = 0;

    ll m = -67;

    for(int i=0;i<7;i++){
        ll q;
        cin>>q;
        sum+=q;
        m = max(m,q);
    }

    sum -= 2*m;
    sum *=-1;
    cout<<sum<<"\n";

}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;

    while(tt--){
        solve();
    }
}
