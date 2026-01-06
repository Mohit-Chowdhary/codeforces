#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    //cin>>t;
    //while(t--){
        ll n;
        cin>>n;
        while(n!=1){
            cout<<n<<" ";
            if(n%2){
                n = n*3 +1;
            }
            else{
                n/=2;
            }
        }
        cout<<n<<endl;
    //}
    return 0;
}