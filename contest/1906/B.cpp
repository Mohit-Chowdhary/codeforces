/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define all(x) x.begin(),x.end()

int sz = 1e6    ;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    int h = 0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        h = max(h,a[i]);
    }

    
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
