#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        cin>>a[0];
        int issame=1;
        for( int i=1;i<n;i++){
            cin>>a[i];
            if(a[i]!=a[i-1]) issame=0;
        }

        if(issame){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            vector<int> sol(a.begin(),a.end());
            reverse(sol.begin()+1,sol.end());
            for(auto &a:sol){
                cout<<a<<" ";
            }
            cout<<endl;
        }
    }
}
