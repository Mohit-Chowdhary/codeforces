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
        if(n==1 || n==3) cout<<"-1\n";
        else if(n==2) cout<<"66\n";
        else{
            string even = "3366", odd = "36366";

            if(n%2){
                for(int i=0;i<(n-5); i++) cout<<3;
                cout<<odd<<"\n";
            }
            else{
                for(int i=0;i<(n-4); i++) cout<<3;
                cout<<even<<"\n";
            }
        }
    }
}