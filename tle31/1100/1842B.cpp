/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];


void func(vector<int>& a, int x, int &cur){
    for(auto &val: a){
        if( (val|x)!=x) break;
        cur |= val;
    }
}

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<int> a(n), b(n), c(n);

    int cur = 0;

    input(a,n); input(b,n); input(c,n);

    func(a,x,cur);
    func(b,x,cur);
    func(c,x,cur);

    if(cur == x){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
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
