/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;
vector<pair<int,int>> maxdist;

int* get_min(int *a, int *b){
    if(*a<*b) return a;
    return b;
}

void solve(){
    int n,k;
    cin>>n>>k;

    a.resize(n);
    maxdist.assign(k+1,{-1,-1});
    vector<int> prev(k+1,-1);
    input(a,n);

    for(int i=0;i<=n; i++){
        if(i<n){
            int* v = get_min(&maxdist[a[i]].first,&maxdist[a[i]].second);
            *v = max(*v, i-prev[a[i]]);
            prev[a[i]] = i;
        }
        else{
            for(int val=0; val<=k; val++){
                int* v = get_min(&maxdist[val].first,&maxdist[val].second);
                *v = max(*v, i-prev[val]);
                prev[val] = i;
            }
        }
    }

    int highest = 1e9;

    for( auto [x,y]: maxdist){
        if(x==-1 && y==-1){
            x = n, y = n;
        }
        int b = max(x,y);
        int s = min(x,y);
        highest = min(highest, max((b+1)/2,s));
    }
    cout<<highest-1<<"\n";

    // int l = 0, r = n;
    // while(l<r){
    //     int m = l + (r-l)/2;
    //     if(can(m,k)){
    //         r = m;
    //     }
    //     else l = m+1;
    // }

    //cout<<l<<"\n";
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
