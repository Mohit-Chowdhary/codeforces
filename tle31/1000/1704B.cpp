#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mi = a[0];
    int ma = mi;
    int count = 0;

    for(int i=1;i<n;i++){
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
        if(ma-mi > 2*x){
            mi = a[i];
            ma = a[i];
            count++;
        }
    }
    cout<<count<<"\n";
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
