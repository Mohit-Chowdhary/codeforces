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
        vector<ll> c(n);
        ll m = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m = max(m,a[i]);
        }
        cout<<m*n<<"\n";
    }
}