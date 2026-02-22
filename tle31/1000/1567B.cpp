#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll xorupto(ll n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}

void solve(){
    ll a,b;
    cin>>a>>b;

    ll pow = 0;

    // while((1<<pow ) <= a){
    //     pow++;
    // }

    ll base =  xorupto(a-1);//(1<<(pow-1))/2;
    //cout<<"aktually "<<actualPow<<"\n\n";

    ll need = base^a;
    if(base == b){
        cout<<a;
    }
    else if(need == a)cout<<a+2;
    else cout<<a+1;
    cout<<"\n";
    
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
