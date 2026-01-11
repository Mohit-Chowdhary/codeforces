#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        int maxsame = 1;
        int curr = 1;
        cin>>n;
        char c[n];
        cin>>c[0];
        for(int i=1;i<n;i++){
            cin>>c[i];

            if(c[i] == c[i-1]){
                curr++;
            }
            else{
                maxsame = max(maxsame, curr);
                curr = 1;
            }
        }
        
        maxsame = max(maxsame, curr);

        cout<<maxsame+1<<"\n";

    }
}