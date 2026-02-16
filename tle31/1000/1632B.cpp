#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    int q = n-1;
    int m = 1;
    do{
        m<<=1;
    }while(m<q);
    if(m!=q) m/=2;
    for(int i=q;i>=m;i--) cout<<i<<" ";
    cout<<"0 ";
    for(int i=m-1; i>0;i--) cout<<i<<" ";
    cout<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
