#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp(n,1);

    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[i]>a[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }

    cout<<*max_element(dp.begin(),dp.end());

}
