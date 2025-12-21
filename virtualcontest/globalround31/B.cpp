#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> input(n);
        cin>>input[0];
        string ans=input[0];
        for(int i=1; i<n; i++){
            cin>>input[i];
            ans =( (ans+input[i]) <(input[i]+ans)  )?(ans+input[i]):(input[i]+ans);
    
        }

        cout<<ans<<endl;
    }
}