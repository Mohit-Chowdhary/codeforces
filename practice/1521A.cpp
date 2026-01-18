#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll A,B;
        cin>>A>>B;
        ll c = min(A,B);
        ll d = max(A,B);
        ll last = c*d;
        ll prod = c;
        // if((c<2 && d<2)){
        //     cout<<"NO\n";
        // }
        if(B==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            //cout<<prod<<" "<<(c)*(d-1)<<" "<<last<<"\n";
            //cout<<prod<<" "<<last<<" "<<(prod+last)<<"\n";
            /*if(c!=1)*/ cout<<A<<" "<<A*B<<" "<<(A+A*B)<<"\n";
            //else cout<<prod<<" "<<last<<" "<<(prod+last)<<"\n";
        }
    }
    return 0;
}
