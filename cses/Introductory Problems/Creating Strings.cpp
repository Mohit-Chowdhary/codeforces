#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

void permute(vector<char>& nums,vector<string>& res, string& curr, vector<bool>& used){
    if(curr.size()==nums.size()){
        res.push_back(curr);
        return;
    }

    for(int i=0; i<nums.size(); i++){
        if(used[i]) continue;

        if( i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;

        used[i] = true;
        curr.push_back(nums[i]);
        permute(nums,res,curr,used);

        curr.pop_back();
        used[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string q;
    cin>>q;
    vector<char> nums(q.begin(),q.end());
    sort(nums.begin(), nums.end());

    vector<bool> used(nums.size(),false);
    vector<string> res;
    string curr = "";

    permute(nums,res,curr,used);
    cout<<res.size()<<"\n";
    for(auto &s: res){
        cout<<s<<"\n";
    }
    
    return 0;
}
