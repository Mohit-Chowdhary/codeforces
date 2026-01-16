#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin>>a;
        int n[a];
        for(int i=0;i<a;i++) {
            cin>>n[i];
            cout<<a + 1 - n[i]<<" ";
        }
        cout<<"\n";
        
    }
    return 0;
}