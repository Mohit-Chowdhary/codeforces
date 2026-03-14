#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int num = int(s[0]-'0');

    int n = s.size();

    bool valid = true;

    for(int i=1; i<n;i++){
        if(s[i]>s[0]){
            break;
        }
        else if(s[i]==s[0]){

        }
        else{
            valid = false;
            break;
        }
    }

    if(!valid) num--;

    int i = n-1;

    int sol = 0;

    while(i>0){
        i--;
        sol+=9;
    }

    sol+=num;

    cout<<sol<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
