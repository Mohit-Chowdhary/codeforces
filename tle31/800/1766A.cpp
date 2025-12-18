#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int total = (int)(s[0]-48) + 9*(s.size()-1);
        cout<<total<<endl;
    
    }
}