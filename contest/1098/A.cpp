/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    map<int,int> m;
    for(auto x:a) m[x]++;

    int count = m[0];

    int left = min(m[1],m[2]);
    count+=left;

    if( (m[1]-left) >0) count+=(m[1]-left)/3;
    if( (m[2]-left) >0) count+=(m[2]-left)/3;


    cout<<count<<endl;
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
