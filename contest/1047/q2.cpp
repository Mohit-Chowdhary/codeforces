#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin>>a;
        int n[a];
        for(int i=0;i<a;i++) cin>>n[i];
        int m=a+1;
        for(int i=0;i<a;i++){
            cout<<m-n[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}