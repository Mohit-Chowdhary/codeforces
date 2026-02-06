#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        string n;
        cin>>n;

        vector<int> dp(n.size(),-1);

        for(int i=n.size()-1;i>=1;i--){
            if(n[i]=='5'){
                for(int j = i-1; j>=0;j--){
                    if(n[j]=='2' || n[j]=='7'){
                        dp[i] = max(j,dp[i]);
                    }
                }
            }
            else if(n[i]=='0'){
                for(int j = i-1; j>=0;j--){
                    if(n[j]=='0' || n[j]=='5'){
                        dp[i] = max(j,dp[i]);
                    }
                }
            }
        }

        cout<<n.size()-2-*max_element(dp.begin(),dp.end())<<"\n";
    }

}
