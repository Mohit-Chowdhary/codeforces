#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

void backtrack(vector<string>& s, int n){
    if(n==0){
        s.push_back("");
        return;
    }

    backtrack(s,n-1);
    int sz = s.size();
    for(int i=sz-1; i>=0; i--){
        s.push_back("1"+s[i]);
    }

    for(int i=0; i<sz; i++){
        s[i] = "0"+s[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> s;
    backtrack(s,n);
    for(auto &a : s){
        cout<<a<<"\n";
    }
    
    return 0;
}
