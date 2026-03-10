/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int j = -1;

    for(int i=1;i<n;i++){
        if(s[i]<s[i-1]){
            j = i;
            break;
        }
    }

    if(j==-1){
        cout<<"NO\n"; return;
    }

    cout<<"YES\n";
    cout<<j<<" "<<j+1<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt;
    // cin>>tt;

    // while(tt--){
        solve();
    // }
}
