#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    vector<ll> a(n+1,0);
    vector<ll> b;
    for(int i=1;i<=n;i++) a[i] = i;
    int j = n;
    if( sum%2==0){
        ll temp = sum;
        ll half = sum/2;
        while(temp < 2*sum){
            if(j<1) break;
            if(j<=half){
                a[j] = 0;
                b.push_back(j);
                half-=j;
                sum-=j;
            }
            j--;
        }
        cout<<"YES\n";
        cout<<b.size()<<endl;
        for(auto &num : b) cout<<num<<" ";
        cout<<endl;
        cout<<n-b.size()<<endl;
        for(auto &num : a){
            if(num!=0) cout<<num<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
