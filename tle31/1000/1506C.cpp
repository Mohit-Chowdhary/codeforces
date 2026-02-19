#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s,n;
    cin>>s>>n;

    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        for(int len = 1; i + len <= s.size(); len++) {
            string sub = s.substr(i, len);
            if(n.find(sub) != string::npos) {
                ans = max(ans, len);
            }
        }
    }

    cout<<((int)s.size()+(int)n.size() - 2*ans)<<"\n";

}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
