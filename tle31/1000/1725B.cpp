#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int N,D;
    cin>>N>>D;

    vector<int> P(N);

    for(int i=0;i<N;i++) cin>>P[i];
    sort(P.begin(), P.end(), std::greater<int>());

    ll out = 0;
    ll times = 0;

    for(int i=0;i<N-out; i++){
        int m = D/P[i]+1;
        if( (N-out-1-i)>=(m-1)){
            out += m-1;
            times +=1;
        }
        else{
            break;
        }
    }

    cout<<times<<"\n";
}

int main(){
    //int tt;
    //cin>>tt;

    //while(tt--){
        solve();
    //}
}
