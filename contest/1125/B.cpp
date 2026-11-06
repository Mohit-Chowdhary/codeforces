/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;

void solve(){
    int n;
    cin>>n;
    deque<int> st;
    vector<bool> can(n,1);
    int m = n;

    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        if(x=='1')st.push_back(i);
        else if(x=='2'){
            if(!st.empty()){
                can[st.back()-1] = 0;
                m--;
                st.pop_back();
            }
            else{
                can[i-1] = 0;
                m--;
            }
        }
        else{
            can[i-1] = 0;
            m--;
        }
    }
    cout<<m<<"\n";;
    for(int i=0;i<n;i++){
        if(can[i]) cout<<i+1<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;

    while(tt--){
        solve();
    }
}
