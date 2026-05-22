/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> pre(n), suff(n);

    pre[0] = a[0]; suff[n-1] = a[n-1];

    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+a[i];
        suff[n-i-1] = suff[n-i] +a[n-i-1];
    }

    int sum = 0;

    int i = 0, j = n-1;

    while(i<j){
        if(pre[i]==suff[j]){
            sum = i+1 + n-j;
            i++;
        }
        else if(pre[i]>suff[j]){
            j--;
        }
        else{
            i++;
        }
    }

    cout<<sum<<"\n";
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
