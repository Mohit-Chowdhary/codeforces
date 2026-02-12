#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int one = count(s.begin(), s.end(), '1');
    int zero = s.size() - one;

    for(auto x:s){
        if(x=='0'){
            if(one>0) one--;
            else{
                break;
            }
        }
        else{
            if(zero>0) zero--;
            else{
                break;
            }
        }
    }

    cout<<one+zero<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
