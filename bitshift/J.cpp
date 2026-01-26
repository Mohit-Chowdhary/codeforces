#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<pair<double, double>> a(n);

        double C = 0.0, V = 0.0;

        for (int i = 0; i < n; i++) {
            cin >> a[i].second; 
            C += a[i].second;
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i].first; 
            V += a[i].first * a[i].second;
        }

        sort(a.rbegin(), a.rend());

        vector<ll> pc(n + 1, 0), pv(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pc[i] = pc[i - 1] + a[i - 1].second;
            pv[i] = pv[i - 1] + a[i - 1].second * a[i - 1].first;
        }

        int L = 1, R = n, block = n;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (pv[mid] * C >= (C - pc[mid]) * V) {
                block = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        ll baseC = pc[block - 1];
        ll baseV = pv[block - 1];
        ll denom = a[block - 1].first;
        ll cnt   = a[block - 1].second;

        ll lo = 0, hi = cnt, take = cnt;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll curC = baseC + mid;
            ll curV = baseV + mid * denom;

            if (curV * C >= (C - curC) * V) {
                take = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << baseC + take << '\n';
    }
    return 0;
}
