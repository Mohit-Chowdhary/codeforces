/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define output(x) for(auto y:x) cout<<y<<" ";
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    input(a,n);

    int curr =a[0], sum = a[0];


    int j=0;

    for(int i=1;i<n;i++){
        if(curr<0){
            curr = a[i];
        }
        else if( (a[i]&1)!= (a[i-1]&1) ){
            curr+=a[i];
        }
        else{
            curr = a[i];
        }
        sum = max(sum,curr);
    }

    cout<<sum<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
