/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()


void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n ;i++) cin>>a[i];

    vector<int> blocks; //sizes of blocks that arent illuminated
    int curr = 0;
    int next = 0;
    for(auto x: a){
        if(next !=0){
            next--;
        }
        if(x!=0){
            curr = max(0,curr - x);
            if(curr!=0) blocks.push_back(curr);
            curr = 0;
            next = x+1;
        }
        else if(next==0 && x==0){
            curr++;
        }
    }
    if(curr!=0) blocks.push_back(curr);

    int count = 0;
    for(auto x: blocks){
        count += (x+2)/3;
    }

    cout<<count<<"\n";
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
