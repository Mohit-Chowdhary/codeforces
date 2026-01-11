#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        unordered_map<int,int> freq;
        for(int i=0; i<k; i++) freq[a[i]]++;

        int mex = 0;
        while(freq[mex]>0) mex++;

        if(mex==k) mex--;
        int maxmex = mex;

        for(int i = k; i<n; i++){
            int out = a[i-k];
            freq[out]--;

            if(out < mex && freq[out] == 0){
                mex = out;
            }

            int in = a[i];
            freq[in]++;

            while(freq[mex]>0) mex++;

            if(mex==k) mex--;
            maxmex = max(maxmex,mex);
        }

        cout<<maxmex<<"\n";
    }
}