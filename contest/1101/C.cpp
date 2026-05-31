/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n,t,ch;
    cin>>n>>t>>ch;

    int empt = t;
    vector<int> tables(t,0);
    int empty = 0;
    int notfull = -1;
    int bank = 0;
    int dupes = 0;

    string s; cin>>s;

    int seated = 0;

    for(auto c:s){
        if(c == 'I'){
            if(empty<t){
                tables[empty]++;
                seated++;
                empty++;
                if(notfull == -1 || empty == notfull) notfull++;
            }
        }
        else if(c == 'A'){
            bank++;
        }
        else if(c == 'E'){
            if(notfull == -1 || notfull == empty){
                if(bank>1) dupes++;
            }
            else{
                tables[notfull]++;
                seated++;
                if(tables[notfull] == ch) notfull++;
            }
        }
    }
    cout<<bank<<" "<<dupes<<endl;
    for(int i=0;i<t;i++){
        cout<<tables[i]<<" ";
        int curr = min(bank, ch-tables[i]);
        bank-=curr;
        seated+=curr;
    }
    cout<<"\n\nans: "<<seated<<"\n\n";
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
