/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

//const ll prime_Size = 150000;
void seive();
//vector<bool> isprime(true,prime_size+1);

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define input(v,x) for(int i=0;i<x;i++) cin>>v[i];

void solve(){
    int n,x,y;
    cin>>n>>x>>y;

    vector<int> prev(n-y+x);
    vector<int> immut(y-x);

    input(prev,x);
    input(immut,y-x);
    for(int i=x;i<n-y+x;i++) cin>>prev[i];

    
    int i = 0;
    for(int k = 1;k<(y-x);k++){
        if(immut[k]<immut[i]) i = k;
    }
    rotate(immut.begin(),immut.begin()+i,immut.end());

    int j=0;
    i=0;
    while(i<prev.size() && j<immut.size()){
        if(prev[i]==immut[j]){
            j++;
            i++;
        }
        else if(prev[i]<immut[j]){
            i++;
            j=0;
        }
        else if(prev[i]>immut[j]){
            break;
        }
    }

    for(int k=0;k<i;k++){
        cout<<prev[k]<<" ";
    }
    for(int k=0;k<immut.size();k++){
        cout<<immut[k]<<" ";
    }
    for(int k=i; k<prev.size();k++){
        cout<<prev[k]<<" ";
    }

    cout<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    // seive();

    while(tt--){
        solve();
    }
}



// void seive(){
//     isprime[0] = false;
//     isprime[1] = false;

//     for(int i=2; i*i<=primesize;i++){
//         if(isprime[i]){
//             for(int j=i*i; j<=prime_size; j+=i){
//                 isprime[j] = false;
//             }
//         }
//     }
// }