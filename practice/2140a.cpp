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
        vector<char> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        int c = count(nums.begin(),nums.end(),'0');

        int sol = 0;

        for(int i=0;i<c; i++){
            if(nums[i] == '1') sol++;
        }
        cout<<sol<<"\n";
    }
}
