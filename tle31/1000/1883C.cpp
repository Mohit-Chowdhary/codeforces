#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;

    int add = k-1;

    int two = 0;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;

        if(m%2==0) two++;
        
        add = min(add, (k-m%k)%k);
    }

    if(k==4 && two>1) add = 0;
    else if(k==4 && two ==1) add = min(1,add);
    else if(k==4) add = min(2,add);

    cout<<add<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
