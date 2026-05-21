/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int curr = 1;
    int l = 0, r = n-1;

    while(l<n && a[l]==b[l]) l++;
    while(r>=0 && a[r]==b[r]) r--;


    while(l>0 && b[l-1]<=b[l]) l--;
    while(r<n-1 && b[r]<=b[r+1]) r++;

    cout<<l+1<<" "<<r+1<<"\n";
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
