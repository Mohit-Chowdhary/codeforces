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
        ll q;
        cin>>q;
        ll a;

        for(int i=1;i<n;i++){
            cin>>a;
            q&=a;
        }

        cout<<q<<"\n";

    }
    return 0;
}
