/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()


void solve(){
    ll t,a,b,c; cin>>t>>a>>b>>c;

    ll x = (t-c) - a*c;
    
    ll an = (t+a+b-1)/(a+b);
    ll be = c + (t-c*a+10*b+a-1)/(10*b+a);

    //cout<<an<<" "<<be<<endl;
    if(an<=c){
        cout<<an<<"\n"; return;
    }
    else{
        cout<<be<<"\n";
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
