#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        while(true){
            long long n1=n;
            int d=0;
            while(n1){
                d+=n1%10;
                n1/=10;
            }
            if(gcd(n,d)>1) break;
            else n++;
        }
        cout<<n<<endl;
    }
    return 0;
}
