#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    int low=0;

    int n1=n;
    int val=n;;

    for(int i=2; i*i<=n1; i++){
        if(n1%i==0){
            val = i;
            break;
        }
    }

    cout<<n/val<<" "<<n-n/val<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
