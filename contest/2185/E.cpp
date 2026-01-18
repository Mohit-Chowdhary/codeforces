#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        vector<long long> a(n), b(m);
        for(auto &x:a) cin >> x;
        for(auto &x:b) cin >> x;

        string gdCode;
        cin >> gdCode;

        sort(b.begin(), b.end());

        unordered_map<long long,int> mp;
        mp.reserve(2*k+5);
        long long cur = 0;
        mp[0] = 0;
        for(int i=0;i<k;i++){
            cur += (gdCode[i]=='R'?1:-1);
            if(!mp.count(cur)) mp[cur] = i+1;
        }

        vector<int> deadAt(k+2,0);

        for(long long x : a){
            int best = INT_MAX;

            auto it = lower_bound(b.begin(), b.end(), x);
            if(it != b.end()){
                long long d = *it - x;
                if(mp.count(d)) best = min(best, mp[d]);
            }
            if(it != b.begin()){
                --it;
                long long d = *it - x;
                if(mp.count(d)) best = min(best, mp[d]);
            }

            if(best != INT_MAX && best <= k) deadAt[best]++;
        }

        int alive = n;
        for(int i=1;i<=k;i++){
            alive -= deadAt[i];
            cout << alive << " ";
        }
        cout << "\n";
    }
    return 0;
}
