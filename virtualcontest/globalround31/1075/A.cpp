#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll n,h,l;
        cin>>n>>h>>l;

        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        int lo = min(h,l);
        int hi = max(h,l);
        sort(a.begin(),a.end());
        int ind1 = 0;
        int ind2 = 0;
        for(int i=0;i<n;i++){
            if(a[i]<=lo) ind1=i+1;
            if(a[i]<=hi) ind2=i+1;
            else{
                break;
            }
        }
        int two = min(ind1,ind2-ind1);
        int one = two;
        if((ind2-ind1)<ind1){
            one += (ind1-two)/2;
        }
        cout<<one<<"\n";
    }
    return 0;
}
