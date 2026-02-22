#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    int m,o;
    cin>>m>>o;
    int diff = o-m;

    int longest = 2;
    int curr = 2;

    for(int i=2;i<n;i++){
        int q;
        cin>>q;
        if((q-o) == diff){
            curr++;
        }
        else{
            curr = 1;
        }
        longest = max(longest,curr);
        o = q;
    }

    cout<<longest<<"\n";
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
