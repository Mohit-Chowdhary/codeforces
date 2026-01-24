#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin>>tt;
    while(tt--){
        ll l,r;
        cin>>l>>r;
        bool valid = true;
        int mi = min(l,r);
        int ma = max(l,r);

        if(mi*2 < ma){
            valid = false;
        }
        if((l+r)%3) valid = false;

        cout<<(valid?"YES":"NO")<<"\n";
    }
    return 0;
}
