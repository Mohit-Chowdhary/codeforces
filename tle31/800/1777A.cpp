#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,i,j,c=0;
        cin>>n;
        n--;
        cin>>i;
        while(n--){
            cin>>j;
            if(i%2 == j%2) c++;
            i=j;
        }
        cout<<c<<endl;
    }
}