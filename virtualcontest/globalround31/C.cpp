#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(int i=0;i<k-1;i++){
            cout<<n<<" ";
        }
        if(k%2==0) cout<<0<<endl;
        else cout<<n<<endl;
    }
}