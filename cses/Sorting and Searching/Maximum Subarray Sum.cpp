#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    ll cursum = a[0];
    ll maxsum = a[0];

    for(int i=1; i<n;i++){
        if(cursum<0){
            cursum = 0;
        }

        cursum+=a[i];

        maxsum = max(maxsum,cursum);
    }

    cout<<maxsum;
}
