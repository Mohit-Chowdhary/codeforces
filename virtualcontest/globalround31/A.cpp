#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int l,a,b;
        cin>>l>>a>>b;
        int elem=a%l;
        for(int i=0;i<5000;i++){
            a = (a+b)%l;
            elem = max(a,elem);
        }
        cout<<elem<<endl;
    }
}