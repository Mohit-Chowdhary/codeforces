/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll total = 0;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        total += a[i];
    }

    // for(int k=0;k<=i;k++){
    //     a.push_back(a[k]);
    //     total+=a[k];
    // }
    // int n = a.size();

    ll bestsize = total;
    int bestindex = -1;
    
    vector<ll> prefix(n+1,0);
    vector<ll> suffix(n+1);
    prefix[1] = abs(a[0]);
    suffix[n] = 0;
    suffix[n-1] = a[n-1];
    for(int i=1;i<n; i++)    prefix[i+1] = prefix[i]+abs(a[i]);
    for(int i = n-2;i>=0; i--)      suffix[i] = suffix[i+1]+a[i];

    /*
    for(auto x: prefix) cout<<x<<" ";
    cout<<endl;
    for(auto x: suffix) cout<<x<<" ";
    cout<<endl<<endl;
    */


    for(int i=n-1;i>=0;i--){
        if(a[i]>0){
            ll curr = prefix[i] + suffix[i] -a[i] - a[i];
            if(curr>=bestsize){
                bestsize = curr;
                bestindex = i;
            }
        }
    }

    bool seeplus = true;
    vector<int> ans;
    for(int i=bestindex-1; i>=0; i--){
        if( (a[i]>0 && seeplus) || (a[i]<0 && !seeplus) ){
            ans.push_back(i+1);
            seeplus^=1;
        }
    }
    if(bestindex!=-1) ans.push_back(bestindex+1);

    int result = ans.size();
    cout<<result<<"\n";
    for(auto x: ans) cout<<x<<" ";
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
