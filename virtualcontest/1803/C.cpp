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

    vector<vector<int>> a;

    for(int i=0;i<n;i++){
        int m;
        cin>>m;

        vector<int> b(m);

        for(int j=0;j<m;j++){
            cin>>b[m-1-j];
        }

        vector<int> c;
        unordered_set<int> seen;

        for(int i=0;i<m;i++){
            if(!seen.count(b[i])){
                c.push_back(b[i]);
                seen.insert(b[i]);
            }
        }

        a.push_back(c);
    }

    int taken = 0;
    unordered_map<int,bool> used;
    unordered_set<int> seen;

    while(taken<n){
        int id=-1;

        for(int i=0;i<n;i++){
            if(used[i]) continue;

            if(id ==-1 || a[i]<a[id])
                id = i;
        }
        taken++;

        used[id] = true;

        for(auto x:a[id]){
            if(!seen.count(x)){
                cout<<x<<" ";
                seen.insert(x);
            }
        }

        for(int i=0;i<n;i++){
            if(used[i]) continue;

            vector<int> temp;

            for(auto x: a[i]){
                if(!seen.count(x))
                    temp.push_back(x);
            }

            a[i] = temp;
        }
    }

    cout<<"\n";
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