#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin>>n;

        ll y = max(1LL, n/4);
        ll x = max(1LL, n/6);
        if(n/6 && n%6) x++;

        if( n%2 || n<4){
            cout<<-1<<"\n";
        }
        else{
            cout<<x<<" "<<y<<"\n";
        }
    }
    return 0;
}
