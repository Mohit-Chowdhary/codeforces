/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll n,t,ch;    
string s; 

ll call(int m){
    ll T = 0, ans = 0;
    for(auto x: s){
        if(x == 'I'){
            if(T<t){
                T++; ans++;
            }
        }
        else if(x == 'E'){
            if(ans < T*ch ){
                ans++;
            }
        }
        else{
            if(m-->0){
                if(T<t){
                    ans++;
                    T++;
                }
            }
            else if(ans<T*ch) ans++;
        }
    }
    return ans;
}

void solve(){
    cin>>n>>t>>ch;
cin>>s;
    ll l =0, r = 0;
    for(char c: s) if(c=='A') r++;

    ll best = 0;

    while(l<r){
        int m = l + (r-l)/2;
        ll one = call(m);
        ll two = call(m+1);

        if(one>two){
            r = m;
        }
        else l = m+1;
    }
    cout<<call(l)<<endl;
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
