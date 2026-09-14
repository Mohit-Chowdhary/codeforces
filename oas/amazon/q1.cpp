/*
    author: Mohit-Chowdhary
    given an array, and k

you have to reduce the array to around k size

you can let a number stay same or pick an element and cut into two parts and add into array (both) or not add it at all (it wasnt given like this but this is what i conclude from description)

select the first k/2 elements(ascending) and return sum
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;

int best;
int n,k;

bool can(int m){
    vector<int> ans;

    for(int i=n-1; i>=0; i--){
        int val = a[i];
        while(val>m){
            ans.push_back(m);
            val-=m;
        }
        if(val!=0) ans.push_back(val);
    }
    int m1 = ans.size();
    if(m1<k) return false;
    sort(ans.begin(),ans.end());
    int cnt = 0;
    int start = m1 - k;

    for (int i = start; i < start + k/2; i++) {
        cnt += ans[i];
    }
    best = max(cnt,best);
    return true;
}

void solve(){
    best = 0;
    cin>>n;
    a.resize(n);
    input(a,n);
    cin>>k;
    int need = k/2;
    vector<int> ans;
    sort(a.begin(),a.end());

    int l = 1, r = accumulate(a.begin(),a.end(),0);

    while(l<r){
        int m = (l+r+1)/2;

        if(can(m)){
            l = m;
        }
        else{
            r = m-1;
        }

    }

    cout<<best<<"\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
