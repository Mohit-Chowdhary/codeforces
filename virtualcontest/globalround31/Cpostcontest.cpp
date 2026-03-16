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
        if(k%2){
            for(int i=0;i<k;i++) cout<<n<<" ";
        }
        else{
            for(int i=0;i<k-2;i++) cout<<n<<" ";

            int x1 = n-1;
            int x2 = x1^n;
            if(x2>n){
                x1 = n;
                x2=0;
            }
            cout<<x1<<" "<<x2;
        }

        cout<<"\n";
    }
}