#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    map<int,int> m;
    int n, count = 0;
    cin>>n;

    for(int j=0;j<n;j++){
        int x;
        cin>>x;
        m[x]++;
    }
    //cout<<"e\n\n"<<i<<"\n\ne";

    while(!m.empty()){
        auto it = prev(m.end());
        int x = it->first;
        int freq = it->second;
        m.erase(it);
        if(freq==1){
            if(x/2!=0) m[x/2]++;
            count++;
        }
    }

    cout<<count<<"\n";
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
