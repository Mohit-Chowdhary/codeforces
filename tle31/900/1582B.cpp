#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        ll n;
        cin>>n;

        ll zero = 0;
        ll one = 0;

        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            if(m==1) one++;
            if(m==0) zero++;
        }

        ll ans = one*(1LL<<zero);

        cout<<ans<<"\n";
    }

}
