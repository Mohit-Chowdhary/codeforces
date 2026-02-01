#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    ll suml = 0;
    ll sumr = 0;
    ll sum  = 0;

    int i = 0;
    int j = n-1;

    while(i<j){
        // suml sumr
    }

    cout<<abs(sum);
}
