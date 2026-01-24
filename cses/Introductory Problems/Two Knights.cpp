#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int t;
    //cin >> t;
    //while(t--){
        int k;
        cin>>k;
        for(int n = 1; n<=k; n++){
            ll sq = n*n;
            ll total = sq*(sq-1)/2;

            ll attacking = max(0, 4*(n-1)*(n-2));

            cout<<total-attacking<<endl;

        }
    //}
    return 0;
}
