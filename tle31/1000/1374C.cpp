/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    stack<char> st;
    int count = 0;
    int hcount = 0;

    for(int i=0;i<n;i++){
        char c;
        cin>>c;

        if(c=='('){
            st.push('(');
            if(count)count--;
        }
        else{
            if(st.empty()) count++;
            else st.pop();
        }

        hcount = max(hcount,count);
    }

    cout<<max((int)st.size(),hcount)<<"\n";
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
