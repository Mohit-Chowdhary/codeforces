#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string ans="No";
        if(n==a && a==b){
            ans="Yes";
        }
        else if((n-a-b)>1) {
            ans="Yes";
        }
        cout<<ans<<endl;
    }
}
