/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> isprime(200000,true);

void seive(){
    isprime[0]=false;
    isprime[1]=false;

    for(int i=2;i*i<200000; i++){
        if(isprime[i]){
            for(int j = i*i; j<200000; j+=i){
                isprime[j] = false;
            }
        }
    }
}

void solve(){
    ll d;
    cin>>d;

    int times = 0;

    ll mul = 1;

    ll p=-1,q=-1;
    ll prev = 1;

    for(int i=2;i<200000;i++){
        if(isprime[i] && i-prev>=d){
            if(p==-1){
                p=i;
                prev = p;
            }
            else{
                q = i;
                break;
            }
        }
    }
    cout<<(1LL*p*q)<<"\n";
}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    seive();

    while(tt--){
        solve();
    }
}
