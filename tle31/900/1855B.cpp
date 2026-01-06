#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int longest = 0;
        int curr = 0;
        for(ll i=1; i<=50; i++){
            if(n%i!=0){
                longest = max(curr,longest);
                curr = 0;
            }
            else curr++;
        }
        longest = max(curr,longest);

        cout<<longest<<endl;
    }
    return 0;
}