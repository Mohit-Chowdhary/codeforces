#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    ll sol = 0;
    unordered_set<ll> s;
    for(int i=0;i<n; i++){
        int a;
        cin>>a;
        if(s.count(a)) continue;
        s.insert(a);
        sol++;

    }

    cout<<sol<<endl;

}
