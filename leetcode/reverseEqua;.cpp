/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

string s1,s2;
int cnt;
int n,m;

void expand(int l, int r){
    while(l>=0 && r<=(n+1) && s2[l] == s1[l] && s1[r]==s2[r]){
        if(s1[l] == s1[r] && r-l>2) cnt++;
        l--;
        r++;
    }
    //cout<<"we got "<<l<<" "<<r<<endl;
    //cout<<s1[l]<<" "<<s1[r]<<endl;
    return;
}

void solve(){
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();

    if(n!=m){
        cout<<"0\n"; return;
    }
    cnt = 0;
    if(s1 !=s2){
        for(int i=0;i<n-1; i++){
            for(int len=2; len+i<=n;len++){
                reverse(s1.begin()+i,s1.begin()+i+len);
                // cout<<s;
                if(s1==s2){
                    cnt++;
                    //cout<<" is accunted";
                }
                reverse(s1.begin()+i,s1.begin()+i+len);
                // cout<<endl;
            }
        }
    }

    if(s1==s2){

        s2 = "#"+s2;
        s2.push_back('#');
        s1 = '#'+s1;
        s1.push_back('#');
        
        for(int i=1; i<=n; i++){
            if(s1[i]==s2[i]){
                expand(i,i);
                if(i>1 && s1[i-1]==s2[i-1]){
                    expand(i-2,i+1);
                }
            }
        }
    }

    cout<<cnt<<"\n";
    
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
