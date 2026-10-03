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
    ll n; cin>>n;

    ll div = 9;
    ll times = 1;

    while(n> div*times){
        n-=div*times;
        div*=10;
        times++;
    }
    //cout<<n<<endl;
    ll num = div/9 + (n-1)/times;

    //cout<<num<<endl;
    ll pos = times-(n-1)%times-1;
    //cout<<pos<<endl;
    while(pos--){
        num/=10;
    }
    cout<<num%10<<"\n";
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
