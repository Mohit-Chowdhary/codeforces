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
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> b;
    int i = n-1;
    while(i>=0 && a[i]<0) i--;
    if(i==-1){
        cout<<"0\n\n";
        return;
    }


    vector<int> ans;
    ll runsum = 0;
    ll total = 0;
    unordered_map<int,ll> m;
    int sz = 1;

    for(int k=0;k<=i;k++){
        b.push_back(a[k]);
        total+=a[k];
    }
    int bsize = b.size();
    m[0] = total;
    
    vector<ll> prefix(bsize+1);
    vector<ll> suffix(bsize+1);
    prefix[1] = abs(b[0]);
    suffix[bsize] = 0;
    suffix[bsize-1] = b[bsize-1];
    for(int i=1;i<bsize; i++)    prefix[i+1] = prefix[i]+abs(b[i]);
    for(int i = bsize-2;i>=0; i--)      suffix[i] = suffix[i+1]+b[i];

    /*
    for(auto x:prefix)cout<<x<<" ";
    cout<<endl;
    for(auto x:suffix)cout<<x<<" ";
    cout<<endl<<endl;
    */

    for(int j=0;j<=i;j++){
        if(  (a[j]>0 ) ){
            ans.push_back(j+1); 
            m[sz] = suffix[j+1] + prefix[j] - abs(b[j]);
            //cout<<"m["<<sz<<"] = "<<m[sz]<<endl;
            sz++;
            if(sz>n) break;
            if(j>0) {
                ans.push_back(j);
                m[sz] = suffix[j+1] - prefix[j] - abs(b[j]);
                //cout<<"m["<<sz<<"] = "<<m[sz]<<endl;
                sz++;
            }
            if(sz>n) break;
        }
    }

    int stopat = -1;
    ll high = LLONG_MIN;

    for(auto &[x,y] : m){
        //cout<<"m["<<x<<"] = "<<y<<endl;
        if(y>high){
            high = y;
            stopat = x;
        }
    }
    if(stopat==-1) stopat = 0;

    cout<< stopat <<"\n";
    for(int i=0;i<stopat;i++) cout<<ans[i]<<" ";
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
