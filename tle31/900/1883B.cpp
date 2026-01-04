#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        char c[n];
        k++;
        map<int,int> h;
        for(int i=0;i<n;i++){
            cin>>c[i];
            h[c[i]]++;
        }
        for(auto &[a,b] : h){
            if(b%2) k--;
        }

        if(k>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}