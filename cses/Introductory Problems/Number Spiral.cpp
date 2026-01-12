#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;

        ll m = max(x,y);
        ll sol;

        if(m%2){
            if(y == m){
                sol = m*m - (x-1);
            }
            else{
                sol = (m-1)*(m-1) + y;
            }
        }

        else{
            if(x == m){
                sol = m*m - (y-1);
            }
            else{
                sol = (m-1)*(m-1) + x;
            }
        }

        cout<<sol<<"\n";
    }

}
