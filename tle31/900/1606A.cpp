#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        string s;
        cin>>s;

        stack<char> st;

        for(auto x: s){
            if(st.empty()){
                st.push(x);
            }
            else if( st.top()!=x){
                if(st.size()==1){
                    st.push(x);
                }
                else{
                    st.pop();
                }
            }
        }
        for(int i=0;i<s.size()-1;i++){
            cout<<s[i];
        }
        if(st.size()==2){
            cout<<(st.top()=='b'?'a':'b');
        }
        else{
            cout<<s[s.size()-1];
        }
        cout<<"\n";
    }

}
