#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        if(n%2==0) cout<<n/2<<" "<<n/2-1<<" "<<1<<"\n";
        else if(n%4==1){
            cout<<n/2-1<<" "<<n/2+1<<" "<<1<<"\n";
        }
        else{
            cout<<n/2-2<<" "<<n/2+2<<" "<<1<<"\n";
        }
    }
}