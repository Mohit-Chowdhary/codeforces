/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];

    vector<int> Aidx(n), Bidx(n), Cidx(n);
    iota(Aidx.begin(), Aidx.end(), 0);
    iota(Bidx.begin(), Bidx.end(), 0);
    iota(Cidx.begin(), Cidx.end(), 0);

    sort(Aidx.begin(), Aidx.end(), [&](int i, int j){
        return a[i]<a[j];
    });
    sort(Bidx.begin(), Bidx.end(), [&](int i, int j){
        return b[i]<b[j];
    });
    sort(Cidx.begin(), Cidx.end(), [&](int i, int j){
        return c[i]<c[j];
    });

    ll sum = LLONG_MIN;

    for(int i=n-1;i>n-4;i--){
        for(int j=n-1; j>n-4; j--){
            if(Aidx[i]==Bidx[j]) continue;
            for(int k= n-1; k>n-4;k--){
                if(Aidx[i]==Cidx[k] || Bidx[j]==Cidx[k]) continue;
                sum = max(sum,a[Aidx[i]]+b[Bidx[j]]+c[Cidx[k]]);
            }
        }
    }

    cout<<sum<<"\n";

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
