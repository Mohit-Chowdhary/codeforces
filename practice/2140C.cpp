#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        vector<int> nums(n);
        ll ans = 0;

        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(i%2) ans-=nums[i];
            else ans+=nums[i];
        }

        ll init = ans;

        for(int i=0;i<n;i++) ans = max(init + i - (i%2), ans);

        ll min_odd = LLONG_MAX/2;
        ll min_even = LLONG_MAX/2;

        for(int i=0;i<n;i++){
            if(i%2){
                ans = max(ans, init + i +nums[i] + nums[i] - min_even);
                min_odd = min(min_odd, 1LL*i - nums[i] - nums[i]);
            }
            else{
                ans = max(ans, init + i - nums[i] - nums[i] - min_odd);
                min_even = min(min_even, 1LL*i + nums[i] + nums[i]);
            }
        }

        cout<<ans<<"\n";
    }
}
