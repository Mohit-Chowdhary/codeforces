/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    string s1;
    s1+=s[0];
    bool prev = (s[0]=='1')?true:false;

    int i=1;
    while(i<n){
        if(s[i]=='0'){
            if(s[i-1]=='1'){
                i++;
                if(i==n){
                    s1+='0'; break;
                }
                s1+=s[i];
            }
            else{
                s1+='0';
                i++;
            }
        }
        else{
            s1+='1'; i++;
        }
    }

    int count = 0;
    for(auto x: s1){
        if(x=='1') count++;
    }

    int count1=0;
    i=0;
    int st = 0;
    while(i<n){
        if(s1[i]=='1'){
            st++;
            if(st==3){
                st=1;
            }
            else{
                count1++;
            }
        }
        else{
            st=0;
        }
        i++;
    }


    cout<<count1<<" "<<count<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
