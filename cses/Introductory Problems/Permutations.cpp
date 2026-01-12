#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    if(n<4){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    int n1 = n;
    for(int i=1; i<=n; i++){
        if(i%2 == 0)cout<<i<<" ";
    }
    for(int i=1; i<=n; i++){
        if(i%2)cout<<i<<" ";
    }
    cout<<"\n";
}