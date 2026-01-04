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
        for(int i=0;i<k-2;i++){
            cout<<n<<" ";
        }
        if(k%2==0){
            int x=0,y=0;
            int n1=n;
            while(n1>0){
                int q=n1>>1;
                if(q){
                    y = y<<1|1;
                    x = x<<1|0;
                } 
                else{
                    y = y<<1|1;
                    x = x<<1|1;
                }
                n1 = n1>>1;
            }
            cout<<x<<" "<<y<<endl;
        }
        else cout<<n<<" "<<n<<endl;
    }
}