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
    pair<int,int> on={0,1000},none ={0,1000}, off={0,1000};

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;

        if(s=="on"){
            on.first = max(on.first,x);
            on.second = min(on.second,y);
        }
        else if(s=="none"){
            none.first = max(none.first,x);
            none.second = min(none.second,y);
        }
        else if(s == "off"){
            off.first = max(off.first,x);
            off.second = min(off.second,y);
        }
    }
    cout<<none.first-on.second<<" "<<none.second-on.first<<"\n";
    cout<<none.first-off.second<<" "<<none.second-off.first<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    while(tt--){
        solve();
    }
}
