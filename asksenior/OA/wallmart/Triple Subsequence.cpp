#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> dp(2001,0);
    int longest = 1;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        if(x%3==0){
            dp[x] = dp[x/3] + 1;
        }
        else{
            dp[x] = 1;
        }

        longest = max(longest, dp[x]);
    }

    cout<<longest<<"\n";
    
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
