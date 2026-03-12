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

void solve(){
    int n;
    cin>>n;

    bool dec = false;

    int prev; cin>>prev;
    
    for(int i=1;i<n;i++){
        int curr;
        cin>>curr;
        if(curr<prev) dec = true;
        prev = curr;
    }

    if(dec){
        cout<<"1\n";
    }
    else{
        cout<<n<<"\n";
    }
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