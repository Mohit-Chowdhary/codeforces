#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        ll a;
        cin>>a;
        //ll c = 1;
        //while(c<a) c*=10;
        // int b = c-a;
        // if(b>0) b--;
        // cout<<b<<"\n";

        //this doesnt work bcuz it gives 0 as output which ideally shodunt come (constraints)


        //editorial
        //x#y=x⋅10d+y=x⋅(10d−1)+(x+y)
        //can be written as x common out
        // = x(10^d + y/x)
        // = x(10^d - x) + (x + y)
        //
        // so now if we make x+y div by x
        // then clear but there is 10^d-1 which id siv by 3

        // so make x+y div by 3
        // so y = 2x


        cout<<2*a<<"\n";
    }
    return 0;
}