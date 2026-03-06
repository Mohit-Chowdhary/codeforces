/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int sum = 0;
    int count = 0;
    unordered_map<int,int> m;
    int start = s[0]-48;
    bool startused = false;

    for(int i=0;i<n;i++){
        int  y = s[i]-48;
        m[y]++;
        sum+=y;
    }

    int maxyet = 9;

    while(sum>9){
        if(m[maxyet]<=0){
            if(maxyet == start){
                startused = true;
                sum++;
            }
            maxyet--;
            continue;
        }
        m[maxyet]--;
        sum-=maxyet;
        count++;
    }
    if(m[maxyet]<=0){
        if(maxyet == start){
            startused = true;
            sum++;
        }
    }

    if(startused && sum>9) count++;
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
