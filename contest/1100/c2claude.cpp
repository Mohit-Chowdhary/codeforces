#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    // prefix[i] = sum of |a[0..i-1]|
    // suffix[i] = sum of a[i+1..n-1] (no abs, untouched)
    vector<ll> prefix(n+1, 0), suffix(n+1, 0);
    for(int i = 0; i < n; i++) prefix[i+1] = prefix[i] + abs(a[i]);
    for(int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + a[i+1];

    // do-nothing baseline
    ll origSum = 0;
    for(auto x : a) origSum += x;

    ll best = origSum;
    int bestIdx = -1;

    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            ll score = prefix[i] + (-a[i]) + suffix[i];
            if(score > best){
                best = score;
                bestIdx = i;
            }
        }
    }

    if(bestIdx == -1){
        cout << "0\n\n";
        return;
    }

    // Reconstruct: easy version loop from bestIdx down to 0
    vector<ll> arr(a.begin(), a.begin() + bestIdx + 1);
    int par = 0;
    vector<int> ans;
    for(int i = bestIdx; i >= 0; i--){
        if(par == 1) arr[i] = -arr[i];
        if(arr[i] > 0){
            ans.push_back(i + 1);
            par ^= 1;
        }
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " \n"[i+1 == (int)ans.size()];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}