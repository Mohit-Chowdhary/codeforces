#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        ll n;
        cin>>n;
        ll asc = 0;
        ll dec = 0;
        ll min4now = 0;

        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                min4now = min(min4now,i-2);
                dec++;
            }
        }

        cout<<n-dec<<"\n";
    }

    return 0;
}
