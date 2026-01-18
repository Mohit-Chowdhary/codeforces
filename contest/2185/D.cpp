#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll n,m,h;
        cin>>n>>m>>h;

        vector<ll> a(n);
        vector<pair<ll,ll>> sum(m,{0,0});

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<m;i++){
            ll b,c;
            cin>>b>>c;
            sum[i].first = b-1;
            sum[i].second = c;
        }

        vector<ll> add(n,0);
        vector<int> seen(n,0);
        int cur_time = 1;

        for(int i=0;i<m;i++){
            int idx = sum[i].first;
            ll val = sum[i].second;

            if(seen[idx] != cur_time){
                seen[idx] = cur_time;
                add[idx] = 0;
            }

            add[idx] += val;

            if(a[idx] + add[idx] > h){
                cur_time++;
            }
        }

        for(int i=0;i<n;i++){
            if(seen[i] == cur_time)
                cout << a[i] + add[i] << " ";
            else
                cout << a[i] << " ";
        }
        cout<<"\n";
    }
}
