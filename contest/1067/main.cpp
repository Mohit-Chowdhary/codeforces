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

        vector<int> a(2*n);
        for (int &x : a) cin >> x;

        unordered_map<int,int> freq;
        for (int x : a) freq[x]++;

        int odd = 0;
        int distinct = freq.size();
        int total=0;

        for (auto &p : freq)
            if (p.second % 2 == 1) odd++;
        for( auto &p:freq)
            total++;

        cout<<odd+2*(total-odd)<<endl;
    }
}
