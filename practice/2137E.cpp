#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> a1(n);
    unordered_map<int,int> m;
    unordered_map<int,int> m1;
    int mex = 0;
    int mex1 = 0;
    int maxel = INT_MIN;
    int maxel1 = INT_MIN;

    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
        maxel = max(maxel,a[i]);
    }
    for(int i=0;i<=maxel; i++){
        if(m[i]>0) mex+=1;
        else if(m[i]==0) break;
    }

    int sum = 0;
    int sum1 = 0;
    //cout<<"\n mex now is "<<mex<<" and maxel "<<maxel<<" \n";

    for(int i=0;i<n;i++){
        int x = a[i];
        //cout<<x<<" and ";
        if(x>mex) {
            sum+=mex;
            a1[i] = mex; m1[a1[i]]++;
        }
        else{
            if(m[x]>1) {
                sum+=mex;
                a1[i] = mex; m1[a1[i]]++;
            }
            else{
                sum+=x;
                a1[i] = x; m1[a1[i]]++;
                //cout<<"same, occurs "<<m[x]<<" times\n";
            }
        }
    }

    
    for(int i=0;i<=maxel1; i++){
        if(m1[i]>0) mex1+=1;
        else if(m1[i]==0) break;
    }

    for(auto x: a1){
        //cout<<x<<" and ";
        if(x>mex1) {
            sum1+=mex1;
        }
        else{
            if(m[x]>1) {
                sum1+=mex1;
            }
            else{
                sum1+=x;
                //cout<<"same, occurs "<<m[x]<<" times\n";
            }
        }
    }

    //cout<<"ans: ";
    if(k%2) cout<<sum<<"\n";
    else cout<<sum1<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
