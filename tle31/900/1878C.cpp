#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        ll n,k,x;
        cin>>n>>k>>x;
        
        if( ((k)*(k+1)/2) <= x && x <=( (n)*(n+1)/2 - (n-k)*(n-k+1)/2 ) ){
            cout<<"YES"<<endl;
            //cout<<((k)*(k+1)/2)<<endl;
            //cout<<( (n)*(n+1)/2 - (n-k)*(n-k+1)/2 )<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}