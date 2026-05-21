/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    ll n = s.size();

    ll left = 0, right = n-1;
    ll countr = 0;

    while(left<n && s[left]=='1') left++;
    while(right>=0 && s[right]=='1') {
        right--; countr++;
    }

    ll sidelen = min(n,left + countr);
    //cout<<left<<" "<<countr<<" "<<n<<endl;
    //cout<<sidelen<<endl;

    ll curr = 0;
    ll m = 0;

    for(ll i=0;i<n;i++){
        if(s[i]=='1') curr++;
        else curr = 0;
        m = max(curr,m);
    }
    m = max(m,sidelen);

    if(m<=1) cout<<m<<"\n";
    else if(m == n) cout<<n*n<<"\n";
    else{
        ll a = (m+1)/2;
        ll b = (m+2)/2;
        cout<<a*b<<"\n";
    }
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
