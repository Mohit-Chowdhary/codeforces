#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int s=0,m;
        for(int i=0;i<n;i++){
            cin>>m;
            s+=m;
        }
        if(s%3==0) cout<<"1 2\n";
        else cout<<"0 0\n";
    }
}