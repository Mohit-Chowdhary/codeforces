#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n1,k;
    cin>>n1>>k;

    set<int> ans;

    for(int i=0;i<n1;i++){
        int m;
        cin>>m;
        ans.insert(m);
    }

    vector<int> a(ans.begin(),ans.end());
    int n = a.size()-1;
    for(int i=0;i<k;i++){
        int q;
        cin>>q;

        int l = 0, h = n;
        int m;
        int found = 1;

        while(l<=h){
            m = l+(h-l)/2;

            if(a[m] == q) {
                found = 0;
                l = m;
                break;
            }
            else if(a[m]>q){
                h = m-1;
            }
            else l = m+1;
        }

        cout<<l<<" "<<n-l+found<<"\n";
    }
}

int main(){
    // int tt;
    // cin>>tt;

    // while(tt--){
         solve();
    // }
}
