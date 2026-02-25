/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    string s;
    cin>>n>>s;

    if(n%2 && s[0] == 'b'){
        cout<<"NO\n";
        return;
    }

    if(n%2){
        int count = 0;
        int rem = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') count++;
            else if(s[i]=='b') count--;
            else rem++;

            while(count<1 && rem>0){
                count++; rem--;
            }
            while(count>2 && rem>0){
                count--; rem--;
            }
            if(count<1 || count>2){
                cout<<"NO\n";
                return;
            }
        }
    }

    else{
        int count = 0;
        int rem = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') count++;
            else if(s[i]=='b') count--;
            else rem++;

            while(count<-1 && rem>0){
                count++; rem--;
            }
            while(count>1 && rem>0){
                count--; rem--;
            }
            cout<<"hmm\n";
            if(count<-1 || count>1){
                cout<<"NO\n";
                return;
            }
        }
    }

    cout<<"YES\n";
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
