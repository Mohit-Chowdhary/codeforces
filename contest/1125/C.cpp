/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    input(a,n);

    vector<ll> sum(n-4);

    for(int i=0;i<n-4; i++){
        sum[i] = a[i]+a[i+2]-a[i+4];
        //cout<<sum[i]<<" ";
    }
    //cout<<endl;
    //i and i+1 can
    // i and i+2 cannot and i and i+4 also cannot others can combine
    // all except for i+2, i+4 form i can join
    // two sum??


    //lets only store latwst 2 indices of each
    unordered_map<ll,deque<ll>> m;
    unordered_map<ll,ll> count;
    ll cnt = 0;
    for(int i=0;i<n-4; i++){
        if(m.count(sum[i])){
            auto val = m[sum[i]];
            auto c = count[sum[i]];
            while(!val.empty()){
                if(val.back()+2 == i || val.back()+4 == i) c--;
                val.pop_back();
            }
            cnt+=c;
        }
        m[sum[i]].push_back(i);
        count[sum[i]]++;
        if(m[sum[i]].size()>4) m[sum[i]].pop_front();
    }

    cout<<cnt<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;

    while(tt--){
        solve();
    }
}
