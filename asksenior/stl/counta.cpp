#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int q; string s;
    cin>>s;

    int n = s.size();
    cin>>q;
    vector<int> a(n+1,0);
    int count = 0;

    for(int i=0;i<n;i++){
        int m=0;
        if(s[i]=='a'){
            m=1;
        }
        a[i+1]+=a[i]+m;
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<a[r]-a[l-1]<<"\n";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
