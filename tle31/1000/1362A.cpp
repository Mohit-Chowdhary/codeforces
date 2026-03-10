/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll a,b;
    cin>>a>>b;

    if(a<b){
        swap(a,b);
    }

    ll times = a/b;

    if(times*b !=a){
        cout<<"-1\n"; return;
    }

    bool valid = true;
    int sol = 0;

    while(times>1){
        if(times%8==0) times/=8;
        else if(times%4==0) times/=4;
        else if(times%2==0) times/=2;
        else{
            cout<<"-1\n";
            return;
        }
        sol++;
    }

    cout<<sol<<"\n";
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
