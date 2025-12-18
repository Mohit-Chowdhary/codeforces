#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        long long a,b;
        cin>>a>>b;
        long long myet=-1;
        if(a%2!=0 && b%2!=0)
            myet=a*b+1;
        else if(a%2==0 && b%2==0){
            myet=a*b/2 + 2;
        }
        else if(a%2!=0 && b%4==0){
            myet=a*b/2+2;
        }
        else{
            myet=-1;
        }
        cout<<myet<<endl;
    }
    return 0;
}