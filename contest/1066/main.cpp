#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int n,k,q; cin>>n>>k>>q;
        vector<pair<int,int>> mins, mexs;
        for(int i=0;i<q;i++){
            int c,l,r; cin>>c>>l>>r;
            if(c==1) mins.emplace_back(l,r);
            else mexs.emplace_back(l,r);
        }

        sort(mexs.begin(), mexs.end());
        vector<pair<int,int>> M;
        for(auto &p: mexs){
            if(M.empty() || p.first > M.back().second)
                M.push_back(p);
            else
                M.back().second = max(M.back().second, p.second);
        }

        vector<int> a(n+1, k);
        vector<char> in_min(n+1), in_mex(n+1), inter(n+1);

        for(auto &p: mins)
            for(int i=p.first;i<=p.second;i++)
                in_min[i]=1;

        for(auto &p: M)
            for(int i=p.first;i<=p.second;i++)
                in_mex[i]=1;

        for(int i=1;i<=n;i++)
            if(in_min[i] && in_mex[i]){ inter[i]=1; a[i]=k+1; }

        for(auto &p: M){
            vector<int> pos;
            for(int i=p.first;i<=p.second;i++)
                if(!in_min[i] && !inter[i])
                    pos.push_back(i);
            for(int j=0;j<(int)pos.size();j++)
                a[pos[j]] = j % k;
        }

        for(auto &p: mins){
            for(int i=p.first;i<=p.second;i++){
                if(!in_mex[i]){ a[i]=k; break; }
            }
        }

        for(int i=1;i<=n;i++){
            if(i>1) cout<<" ";
            cout<<a[i];
        }
        cout<<"\n";
    }
}
