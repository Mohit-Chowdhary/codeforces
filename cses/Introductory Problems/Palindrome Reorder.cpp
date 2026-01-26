#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(auto &a : s){
        m[a]++;
    }
    int odd = 0;
    vector<char> ans;
    char mid;
    for(auto &[a,b] : m){
        if(b%2){ 
            odd++;
            mid = a;
        }
        for(int i=0;i<b/2;i++){
            ans.push_back(a);
        }
    }

    if(odd>1){
        cout<<"NO SOLUTION\n";
    }
    else{
        for(auto a: ans){
            cout<<a;
        }
        if(odd)cout<<mid;
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i];
        }
    }
    return 0;
}
