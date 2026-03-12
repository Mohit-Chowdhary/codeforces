    /*
        author: Mohit-Chowdhary
    */

    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    bool valid(ll s, ll m, ll lim){
        ll f = 0;
        for(int i=59; i>=0;i--){
            f<<=1;
            if((s>>i)&1){
                f++;
            }
            if((m>>i)&1){
                f -= min(lim,f);
            }
        }

        return f==0;
    }

    void solve(){
        ll s,m;
        cin>>s>>m;

        ll l = 0, r = 1ll<<60;
        if(!valid(s,m,r)){
            cout<<"-1\n";
            return;
        }

        while(l<r){
            ll mi = l +(r-l)/2;

            if(valid(s,m,mi)){
                r = mi;
            }
            else{
                l = mi+1;
            }
        }

        cout<<l<<"\n";

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
