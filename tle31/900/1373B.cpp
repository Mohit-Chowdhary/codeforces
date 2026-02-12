#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int one = count(s.begin(),s.end(),'1');
    int zero = count(s.begin(),s.end(),'0');

    int m = min(one,zero);

    if(m%2){
        cout<<"DA\n";
    }
    else{
        cout<<"NET\n";
    }
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
