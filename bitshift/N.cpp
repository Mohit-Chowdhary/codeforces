#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        ll sum = 0, lo = 0;
        for (int i = 0; i < k; i++) {
            ll a;
            cin >> a;
            sum += a;
            lo = min(lo, sum);
        }

        ll rem = -lo;
        rem = min(rem,(ll)s.size());
        s.resize(s.size() - rem);

        ll zero = rem + sum;
        if (zero < 0) zero = 0;

        size_t pos = s.find_first_not_of('0');

        if (pos == string::npos) {
            cout << "0\n";
            continue;
        }

        cout << s.substr(pos);

        for (ll i=0; i<zero; i++) cout << '0';

        cout << '\n';
    }

    return 0;
}
