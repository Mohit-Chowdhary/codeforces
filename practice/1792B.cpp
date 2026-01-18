#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        if(a[0]==1) a[0]++;
        cout<<a[0];
        for(int i=1;i<n;i++){
            if(a[i]==1) a[i]++;
            if(a[i]%a[i-1]==0){
                a[i]++;
            }
            cout<<" "<<a[i];
        }
        cout<<"\n";
    }
}