#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin>>n;

        vector<ll> a(n);

        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());

        ll freq=1;
        ll curr = 1;
        // unordered_map<ll, ll> m;
        // for(auto &num: a){
        //     m[num]++;
        //     freq = max(freq,m[num]);
        // }
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                curr++;
            }
            else{
                curr = 1;
            }
            freq = max(curr,freq);
        }

        ll clone = 0;
        ll empty = n-freq;
        while(freq<n){
            freq*=2;
            clone++;
        }
        cout<<clone+empty<<"\n";

    }
    return 0;
}
