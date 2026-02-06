#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        ll a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<" "<<0<<"\n";
            continue;
        }
        ll c = abs(a-b);

        cout<<c<<" "<<min(a%c,c-a%c)<<"\n";
    }

}
