/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define all(x) x.begin(),x.end()

bool isplaind(vector<ll>& a){
    int i=0, j = a.size()-1;

    while(j>i){
        if(a[j--]!=a[i++]) return false;
    }
    return true;
}

void solve(){
    ll n;
    cin>>n;

    vector<ll> a(n);

    input(a,n);
    if(isplaind(a)){
        cout<<0<<"\n";
        return;
    }

    int lc = abs(a[0]-a[n-1]);

    int i=1, j = n-2;

    while(j>i){
        int b = abs(a[i]-a[j]);
        i++; j--;

        lc = gcd(lc,b);
    }

    cout<<lc<<"\n";
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
