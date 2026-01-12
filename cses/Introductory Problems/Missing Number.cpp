#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int t;
    //cin>>t;
    //while(t--){
        int n;
        int num = 0;
        cin>>n;
        for(int i=0; i<n-1; i++){
            int a;
            cin>>a;
            num^=a;
            num^=(i+1);
        }
        num^=n;
        cout<<num<<"\n";

    //}
}