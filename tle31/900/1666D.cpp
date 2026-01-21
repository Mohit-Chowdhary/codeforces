#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--){
        string s,t;
        cin>>s>>t;
        unordered_map<char,int> key;
        unordered_map<char,int> m;

        // for(auto &a: t){
        //     key[a]++;
        // }

        bool valid = true;
        int j = t.size()-1;

        for(int i=s.size()-1; i>=0;i--){
            int minus = 0;
            if(j<0) break;
            if(s[i] == t[j] ){
                //cout<<s[i]<<" "<<t[j]<<endl;
                key[t[j]]++;

                minus = 1;
            }
            if(m[s[i]] >= key[t[j]] && t[j]==s[i]){
                //cout<<"at "<<s[i]<<" "<<t[j]<<endl;
                valid = false;
                break;
            }
            j-=minus;
            
            m[s[i]]++;
            
        }
        
        //cout<<endl;
        //cout<<j<<endl;
        if(valid && j==-1){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
