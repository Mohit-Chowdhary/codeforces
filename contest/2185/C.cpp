#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll m = 1;
        ll curr= 1;
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                continue;
            }
            else if(a[i]==a[i-1]+1){
                curr++;
            }
            else{
                curr=1;
            }
            m = max(curr,m);
        }
        cout<<m<<"\n";
    }
}