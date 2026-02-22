#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    unordered_map<int,int> m;
    ll curr = 0;
    int u=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i] % 2 == 0) a[i]--; 
    }

    for(int i=0;i<k;i++){
        int x = a[i];
        m[x]++;
        if(m[x]==1){
            u++;
        }
        curr+=(ll)x;
    }

    ll maxsum = 0;
    if(u==k) maxsum = curr;

    for(int i=k;i<n;i++){
        int x = a[i];
        int y = a[i-k];
        m[x]++;
        if(m[x]==1){
            u++;
        }
        m[y]--;
        if(m[y] == 0){
            u--;
        }
        curr+=(ll)x;
        curr-=(ll)y;
        //cout<<i<<" idx "<<curr<<" u "<<u<<"\n";

        if(u==k){;
            maxsum = max(curr,maxsum);
        }
    }

    cout<<maxsum<<"\n";

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
