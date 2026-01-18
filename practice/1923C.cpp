#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        int n,q;
        cin>>n>>q;
        vector<ll> nums(n);
        vector<ll> pre(n+1,0);
        vector<ll> one(n+1,0);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            pre[i+1] = pre[i] + nums[i];
            one[i+1]+= one[i] + (nums[i]==1);
        }

        for(int i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            --l;

            //cout<<r-(l-1)<<" "<<pre[r]<<" "<<pre[l-1]<<" "<<one[r]<<" "<<one[l-1]<<endl;

            ll ind = one[r] - one[l];
            ll diff = pre[r] - pre[l];

            if( ((r-l)+ind) <= diff && r-l>1){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }

    }
}