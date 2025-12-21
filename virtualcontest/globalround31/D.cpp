#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> dist;
        int prev;
        cin>>prev;
        int next;
        for(int i=1;i<n;i++){
            cin>>next;
            dist.push_back(next-prev);
            prev=next;
        }
        int total=0;
        int i=0;
        for(i ;i<n-2;i++){
            if(dist[i]<=dist[i+1]) total++;
            //cout<<" dist "<<i<<" "<<dist[i]<<endl;
        }
        cout<<total+1<<endl;
    }
}