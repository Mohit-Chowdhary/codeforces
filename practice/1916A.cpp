#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        int n,k;

        cin>>n>>k;
        int q = 2023;
        int m;
        int s=1;
        bool no = false;
        for(int i=0; i<n;i++){
            cin>>m;
            if(s>q){
                no = true;
                s=0;
            }
            s*=m;
        }

        if(no){
            cout<<"NO\n";
        }

        else if(q%s == 0){
            int w = q/s;
            vector<int> ans;
            cout<<"YES\n";
            while(k--){
                if(w==1){
                    ans.push_back(1);
                }
                else if(w>16){
                    ans.push_back(17);
                    w/=17;
                }
                else if(w>6){
                    ans.push_back(7);
                    w/=7;
                }
            }
            if(w>1){
                int m = ans.back();
                ans.pop_back();
                ans.push_back(w*m);
            }
            for(auto &a : ans){
                cout<<a<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"NO\n";
        }

    }
}