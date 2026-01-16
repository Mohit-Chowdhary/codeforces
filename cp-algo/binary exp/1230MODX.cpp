#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;

        ll sol = 1;
        while(y>0){
            if(y&1){
                sol *= x;
                sol %=n;
            }
            x *= x;
            x %= n;
            y>>=1;
        }

        cout<<sol<<"\n";
    }
    int m;
    cin>>m;

}
