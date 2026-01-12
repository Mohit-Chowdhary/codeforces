#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    ll sol = 0;
    ll a,b;
    cin>>a;
    for(int i=1;i<n;i++){
        cin>>b;
        if(b<a){
            sol+=a-b;
            b=a;
        }
        a=b;
    }
    cout<< sol<<"\n";
}