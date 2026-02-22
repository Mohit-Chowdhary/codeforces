#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    ll sum = 0;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }

    ll lowest = LLONG_MAX;
    for(int i=0; i<(1<<n); i++){
        ll curr = 0;
        for(int j = 0; j<n; j++){
            if(j&i){
                curr+=a[j];
            }
        }
        if( sum - 2*curr == 0){
            lowest = min(lowest, curr);
        }
    }

    cout<<(lowest==LLONG_MAX?0:lowest)<<"\n";
    
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
