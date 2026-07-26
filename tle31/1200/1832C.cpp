/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    int inc = -1;

    vector<int> ans;
    int j=0;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>ans[j]){
            if(inc==1){
                ans.pop_back();
            }
            else{
                inc = 1;
                j++;
            }
            ans.push_back(a[i]);
        }
        else if(a[i]<ans[j]){
            if(inc==0){
                ans.pop_back();
            }
            else{
                inc = 0;
                j++;
            }
            ans.push_back(a[i]);
        } 
    }
    cout<<j+1<<"\n";
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
