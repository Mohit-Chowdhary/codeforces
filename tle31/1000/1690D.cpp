#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int w = 0;

    for(int i=0;i<k;i++){
        if(s[i] == 'W') w++;
    }
    int m = w;
    for(int i=0;i<n-k;i++){
        if(s[i] == 'W') w--;
        if(s[i+k] == 'W') w++;
        m = min(m, w);
    }

    cout<<m<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
