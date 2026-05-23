/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int i=0, j = n-1;

    while(i<j){
        if(a[i]==a[j]){
            i++; j--;
        }
        else break;
    }

    int first = a[i], second = a[j];

    vector<int> b1,b2;

    for(auto c:a){
        if(c!=first) b1.push_back(c);

        if(c!=second) b2.push_back(c);
    }

    bool can = true;
    for(int i=0;i<b1.size()/2;i++){
        if(b1[i] != b1[b1.size()-i-1]){
            can = false; break;
        }
    }

    if(can){
        cout<<"YES\n"; return;
    }

    can = true;
    for(int i=0;i<b2.size()/2;i++){
        if(b2[i] != b2[b2.size()-i-1]){
            can = false; break;
        }
    }
    if(can){
        cout<<"YES\n"; return;
    }
    cout<<"NO\n";
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
