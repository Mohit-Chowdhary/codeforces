#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        bool valid = true;
        //cout<<a<<" "<<b<<" "<<c<<"\n";
        int new_c = (2*(b-a)+a);
        int new_b = a+ (c-a)/2;
        int new_a = (2*b-c);
        if( a-b == b-c){
            valid = true;
        }
        else if( new_c>0 && new_c%c ==0 ){
            valid  = true;
        }
        else if(new_a>0 && new_a%a == 0){

        }
        else if( new_b>0 &&  new_b%b==0 && (c-a)%2==0){
            
        }
        else{
            valid = false;
        }

        if(valid) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
