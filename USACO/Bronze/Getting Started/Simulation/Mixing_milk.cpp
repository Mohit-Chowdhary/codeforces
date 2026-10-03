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
    int c1,c2,c3,a,b,c;
    cin>>c1>>a>>c2>>b>>c3>>c;

    int A=a,B=b,C=c;
    int sum = A+B;
    B = min(c2, sum);
    A = sum - B;
    sum = B+C;
    C = min(c3, sum);
    B = sum-C;
    sum = C+A;
    A = min(c1, sum);
    C = sum-A;
    sum = A+B;
    B = min(c2, sum);
    A = sum - B;

    cout<<A<<"\n"<<B<<"\n"<<C<<"\n";

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
