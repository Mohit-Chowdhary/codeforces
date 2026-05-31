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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    //for(auto x: a) cout<<x<<" ";
    //cout<<endl;
    int count = 0;

    int k = n/2;
    int i = k-1;
    int j = k;
    if(n%2) j++;

    while(i>=0 &&j<n){
        if(a[i--] != a[j++]) count++;
    }
    cout<<count<<"\n";


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
