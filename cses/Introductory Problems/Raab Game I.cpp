/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;

void solve(){
    /*
        sum <= count
        max possible wins = n-1, last, other no shd win
        max draw = n

        cant hve  1 win and all other draw

        if a non zero then b must be non zero
        if any a,b 0, other must be 0 as well

        otherwise all ok??
    */
    int n,a,b;
    cin>>n>>a>>b;
    int a1=a,b1=b;

    if(a==n || b==n || a+b>n || (a<1 && b>0) || (b<1 && a>0)){
        cout<<"NO\n";
        return;
    }
    int draw = n-a-b;

    // count a wins
    int A = n, B = n;
    vector<pair<int,int>> ans;
    while(a1--){
        ans.emplace_back(A,A-b);
        A--;
    }
    while(b1--){
        ans.emplace_back(A,B);
        B--;
        A--;
    }
    while(draw--){
        ans.emplace_back(draw+1,draw+1);
    }
    cout<<"YES\n";
    for(auto [x,y]: ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto [x,y]: ans){
        cout<<y<<" ";
    }
    cout<<"\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;

    while(tt--){
        solve();
    }
}
