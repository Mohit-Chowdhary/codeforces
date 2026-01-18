#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll n,q;
        cin>>n>>q;
        vector<ll> a(n);
        vector<ll> sum(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum[i+1] = a[i] + sum[i];
        }

        for(int i=0;i<q;i++){
            ll l,r,k;
            cin>>l>>r>>k;

            l--;

            int rest = (sum[n] - (sum[r] - sum[l]) )%2;
            int curr = (k%2 && (r-l)%2);

            if(rest!=curr) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}