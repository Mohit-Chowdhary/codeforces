#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dpL(n,1);
    vector<int> dpR(n,1);

    int maxL = 1;
    int maxR = 1;

    for(int i=1;i<n;i++){
        for(int j=i-1; j>=0;j--){
            if(a[i]>a[j]){
                dpL[i] = max(dpL[i],1+dpL[j]);
                maxL = max(maxL,dpL[i]);
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                dpR[i] = max(dpR[i],1+dpR[j]);
                maxR = max(maxR,dpR[i]);
            }
        }
    }

    int ans = max(maxL,maxR);;

    cout<<ans;
}
