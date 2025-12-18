#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string mode;
    cin >> mode;

    if (mode == "first") {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Encode
        string s;
        // store n in 2 letters (base-26)
        s += char('a' + (n / 26));
        s += char('a' + (n % 26));

        // store array elements
        for (int x : a) s += char('a' + (x - 1));

        cout << s << "\n";
    }
    else if (mode == "second") {
        string s;
        cin >> s;

        // Decode
        int n = (s[0] - 'a') * 26 + (s[1] - 'a');
        vector<int> a;
        for (int i = 2; i < (int)s.size(); i++)
            a.push_back((s[i] - 'a') + 1);

        cout << n << ' ';
        for (int x : a) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
