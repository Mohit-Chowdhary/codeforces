#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;

        a--;

        ll total = b;
        ll in;
        while(n--){
            cin>>in;
            in = in<a?in:a;
            total+= in;
        }

        cout<<total<<endl;
    }
}