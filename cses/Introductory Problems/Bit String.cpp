#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    ll sol = 1;
    while(n>0){
        sol <<=1;
        sol=sol%MOD;
        n--;
    }
    cout<< sol <<endl;
    return 0;
}
