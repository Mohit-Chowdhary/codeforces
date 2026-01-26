#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    ll sol = 1;
    vector<int> a(n);
    for(int i=0;i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]) sol++;
    }

    cout<<sol<<endl;

}
