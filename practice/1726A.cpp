#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        int maxel = INT_MIN;
        int minel = INT_MAX;
        int maxadj = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maxel = max(maxel,a[i]);
            minel = min(minel,a[i]);
            if(i>0){
                maxadj = max(maxadj, a[i-1] - a[i] );
            }
        }
        maxadj = max(a[n-1]-a[0], maxadj);
        int one = maxel-a[0];
        int two = a[n-1] - minel;
        cout<<max({maxadj,one,two})<<"\n";
    }
}