#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n <= 6) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int r = 0; r < 3; r++) {
        for (int i = r; i <= n; i += 3) {
            if (i > 0) cout << i << " ";
        }
    }
    cout << "\n";
}
