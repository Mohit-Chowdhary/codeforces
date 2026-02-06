#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        ll x,n;
        cin>>x>>n;

        if(x%2==0){
            int m = n%4;
            if(m==0){
                cout<<x<<"\n";
            }
            else if(m==1){
                cout<<x+(-1*(4*n/4))<<"\n";
            }
            else if(m==2){
                cout<<x+1<<"\n";
            }
            else{
                cout<<x+(4+4*(n/4))<<"\n";
            }
        }
        else{
            int m = n%4;
            if(m==0){
                cout<<x<<"\n";
            }
            else if(m==1){
                cout<<x+(1+4*(n/4))<<"\n";
            }
            else if(m==2){
                cout<<x-1<<"\n";
            }
            else{
                cout<<(-4*(1+n/4) +x)<<"\n";
            }
        }
    }

}
