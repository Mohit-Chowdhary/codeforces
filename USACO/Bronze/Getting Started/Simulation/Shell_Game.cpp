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
    vector<int> A(3),B(3);
    iota(A.begin(),A.end(),0);
    
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        swap(A[a-1],A[b-1]);
        B[A[c-1]]++;
    }
    int ans = *max_element(B.begin(), B.end());
    cout<<ans<<"\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    while(tt--){
        solve();
    }
}
