#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    int a[2*n]={0};
    int b[2*n]={0};

    int count = 1;
    int num;
    cin>>num;
    for(int i=1; i<n;i++){
        int m;
        cin>>m;
        if(m==num) count++;
        else{
            a[num-1]= max(a[num-1],count);
            count = 1;
        }
        num = m;
    }
    a[num-1]= max(a[num-1],count);
    count = 1;
    cin>>num;
    for(int i=1; i<n;i++){
        int m;
        cin>>m;
        if(m==num) count++;
        else{
            b[num-1]= max(b[num-1],count);
            count = 1;
        }
        num = m;
    }
    b[num-1]= max(b[num-1],count);

    int ans = 0;
    for(int i=0;i<2*n; i++){
        ans = max(ans, a[i]+b[i]);
    }
    cout<<ans<<"\n";
    return;
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
