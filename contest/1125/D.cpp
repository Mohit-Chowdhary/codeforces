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

bool sgn(ll x){
    if(x>0) return 1;
    return 0;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<int> pos(n,0);
    vector<ll> cost(n,0);
    for(int i=0;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x>y || x>z || y>z) pos[i]=1;
        else if(x==y && x==z && y==z){
            pos[i]=-1;
        }
        else{
            cost[i] = min(y-x+1,z-x+1);
        }
        a[i] = x+y+z;
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    // use set

    // lowerbound to get next elem
    // k-2*m is it
    set<pair<ll,int>> s;

    for(int i=0;i<n;i++){
        //pq.push({a[i],i});
        s.insert({a[i],i});
    }

    while(k>0){
        auto [mn,i] = *s.begin();
        if(pos[i]==-1){
            break;
        }
        if(pos[i] == 0){
            k-=cost[i];
            if(k<=0) break;
            pos[i] = 1;
            mn-=cost[i];
        }
        auto x = s.upper_bound({mn,INT_MAX});
        int diff = distance(s.begin(), x);
        if(x == s.end()){
            cout<<mn+k/diff<<"\n";
            return;
        }
        
        auto [mn1,j] = *s.upper_bound({mn,i});
        
        ll hi = mn1-mn;
        ll add = (k-hi*diff)/2;
        if(add==0){
            cout<<mn<<"\n";
            return;
        }
        s.erase({mn,i});
        s.insert({mn+add,i});
        k-=add;
    }

    // too slow
    // somehow take top 2 best and add the diffrence
    // while(k>0){
    //     auto [mn,i] = pq.top();
    //     if(pos[i]==-1){
    //         break;
    //     }
    //     if(!pos[i]){
    //         //cout<<"at "<<i<<" cost is "<<cost[i]<<", k is "<<k<<endl;
    //         k-=cost[i];
    //         if(k<=0) break;
    //         pos[i] = 1;
    //         mn-=cost[i];
    //     }
    //     pq.pop();
    //     if(pq.empty()){
    //         pq.push({mn+k,i});
    //         k=0;
    //         break;
    //     }
    //     auto [mn1,j] = pq.top();
    //     //cout<<k<<"\n";

    //     ll diff =1;
    //     diff = min(k,mn1-mn);
    //     if(diff == 0) diff = 1;
    //     pq.push({mn+k-2*diff,i});
    //     k-=diff;
    // }

    //auto [mn,i] = pq.top();
    auto [mn,i] = *s.begin();
    cout<<mn<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin>>tt;

    while(tt--){
        solve();
    }
}
