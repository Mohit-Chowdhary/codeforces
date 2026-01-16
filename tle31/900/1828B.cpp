#include <bits/stdc++.h>
using namespace std;

#define ll long long

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);

        for(int i=0;i<n;i++) cin>>nums[i];

        int div = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] != i+1){
                int diff = abs(nums[i]-i-1);
                div = gcd(div,diff);
            }
        }

        cout<<div<<"\n";
    }

}
