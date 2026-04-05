    /*
        author: Mohit-Chowdhary
    */

    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    #define output(x) for(auto y:x) cout<<y<<" ";
    #define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

    ll count(vector<ll>& a, ll h){
        ll sum = 0;

        for(auto x:a){
            sum += max(h-x,0LL);
        }

        return sum;

    }

    void solve(){
        ll n,x;
        cin>>n>>x;
        ll hi = 0;

        vector<ll> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
            hi = max(hi,a[i]);
        }

        ll r = hi+x/n;
        ll l = 1;

        while(l<=r){
            ll h = l + (r-l)/2;

            ll sum = count(a,h);

            if(sum <= x){
                l = h+1;
            }
            // else if(sum<x){
            //     l = h+1;
            // }
            else{
                r = h-1;
            }
        }

        cout<<l-1<<"\n";
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
