#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        int m = a[i] - a[i-1];
        if(m<0){
            if(st.size()%2){
                st.pop();
            }
            st.push(i);
        }
        else{
            if(st.size()%2==0){
                st.pop();
            }
            st.push(i);
        }

        if(st.size()>=3) break;
    }

    if(st.size()>=3){
        cout<<"YES\n";
        int right = st.top()+1;
        st.pop();
        int mid = st.top()+1;
        st.pop();
        int left = st.top()+1;
        cout<<left<<" "<<mid<<" "<<right<<"\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
