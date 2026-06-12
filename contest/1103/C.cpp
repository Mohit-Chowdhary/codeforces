/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()


void solve(){
    ll a,b,x; cin>>a>>b>>x;
    priority_queue<int, vector<int>, greater<int>> curbest;
    int count = 0;
    while(a!=b){
        if(abs(a-b) == 1){
            count++;
            break;
        }
        else if( a/x == b/x){
            count+=2;
            break;
        }
        else if(a>b){
            //cout<<a<<" and "<<b<<endl;
            // if(abs(a-b)<= (2+abs(a/x -b/x))){
            //     count += abs(a-b);
            //     break;
            // }
            curbest.push(count+abs(a-b));
            a/=x;
            count++;
        }
        else if(b>a){
            // if(abs(a-b)< (2+abs(b/x -a/x))){
            //     count += abs(a-b);
            //     break;
            // }
            curbest.push(count+ abs(a-b));
            b/=x;
            count++;
        }
    }
    int be = curbest.empty()? INT_MAX: curbest.top();
    count = min(be, count);
    cout<<count<<"\n";
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
