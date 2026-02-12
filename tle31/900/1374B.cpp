#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    int two=0, three=0;

    while(n%2==0){
        n/=2;
        two++;
    }
    while(n%3==0){
        n/=3;
        three++;
    }

    if(n!=1 || two>three){
        cout<<"-1\n";
    }
    else{
        cout<<2*(three-two)+two<<"\n";
    }
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
