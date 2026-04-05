/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;;


#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define input(v,x) for(int i=0;i<x;i++) cin>>v[i];

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(60,0);

    for(int i=0;i<m;i++){
        ll q;
        cin>>q;
        ll count = 0;
        while(q>1) {
            q>>=1;
            count++;
        }
        a[count]++;
    }

    ll ops = 0;

    for(ll i=0;i<60;i++){
        ll need = (n>>i)&1;

        if(need>a[i]){
            ll j=i+1;

            while(j<60 && a[j]==0) j++;

            if(j==60){
                cout<<"-1\n";
                return;
            }

            while(j>i){
                a[j]--;
                a[j-1]+=2;
                j--;
                ops++;
            }
        }

        a[i]-=need;
        if(i<59) a[i+1]+=a[i]/2;
    }

    cout<<ops<<"\n";
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