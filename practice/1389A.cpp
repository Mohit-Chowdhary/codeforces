#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll l,r;

        cin>>l>>r;

        if(l*2>r){
            cout<<"-1 -1\n";
        }
        else cout<<l<<" "<<2*l<<"\n";

    }
}