#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    queue<int> q;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        q.push(m);
        cout<<m<<" ";
    }

    while(!q.empty()){
        int sz = q.size();

        for(int i=0;i<sz-1;i++){
            int val = q.front();
            q.pop();

            int newval = max(val,q.front());
            cout<<newval<<" ";
            q.push(newval);
        }
        q.pop();
    }
    cout<<"\n";
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
