#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);

        for(int i=0;i<n;i++) cin>>a[i];

        int count=0;
        bool possible  = true;
        for(int i=n-1;i>0; i--){
            while(a[i-1]>=a[i]){
                if(a[i-1]==0) {
                    possible = false;
                    break;
                }
                a[i-1]/=2;
                count++;
            }
        }
        if(possible) cout<<count<<"\n";
        else cout<<"-1\n";


    }
    return 0;
}
