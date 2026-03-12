/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

const ll prime_size = 1000000;
void seive();
vector<bool> isprime(prime_size+1,true);

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define input(v,x) for(int i=0;i<x;i++) cin>>v[i];

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    input(a,n);

    int l = 0, r = n-1;
    int res = 0;

    while(r-l>1){
        int it = (int)(max_element(a.begin()+l,a.begin()+r+1) - a.begin());

        //cout<<"iter is "<<it<<endl;
        if((it-l) >(r-it)){
            res+= r-it;

            r = it-1;
        }
        else{
            res+= it-l;

            l= it+1;
        }
    }

    cout<<res<<"\n";
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