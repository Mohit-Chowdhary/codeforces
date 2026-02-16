#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    cin>>a[0];
    int prev = 0;
    bool valid = true;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]){
            if(!valid) continue;
            if(i-prev ==1 ){
                valid = false;
                continue;
            }
            rotate(ans.begin()+prev, ans.begin()+prev+1,ans.begin()+i);
            prev = i;
        }
    }
    if(n==1) valid = false;
    if(valid && a[n-1] !=a[n-2]) valid = false;
    rotate(ans.begin()+prev, ans.begin()+prev+1,ans.begin()+n);

    if(!valid){
        cout<<"-1\n";
        return;
    }
    else{
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";

    }
    cout<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
