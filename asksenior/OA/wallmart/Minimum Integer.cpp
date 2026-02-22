#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    int sol = INT_MAX;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;

        sol&=m;
    }

    cout<<sol<<"\n";
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
