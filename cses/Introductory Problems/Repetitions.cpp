#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int curr = 1;
    int sol = 1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]) curr++;
        else{
            curr = 1;
        }
        sol = max(sol,curr);
    }

    cout<<sol<<"\n";
}