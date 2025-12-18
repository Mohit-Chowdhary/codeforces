#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        unordered_map<int, int> dp;
        int best=0;

        for (int x : a) {
            int cand =1 +best;
            if (dp.count(x - 1) && dp[x - 1] == best) {
                int second_best = 0;
                for (auto &[val, len]: dp)
                    if (val != x -1 ){
                        second_best= max(second_best, len);
                    }
                cand =1+ second_best;
            }
            dp[x] = max(dp[x], cand);
            best = max(best, dp[x]);
        }

        cout<< n - best << "\n";
    }
}
