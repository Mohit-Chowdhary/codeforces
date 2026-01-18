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
        int intervals = 0;
        int start = 0;
        cin>>a[0];
        if(a[0]) start=1;
        for(int i=1;i<n;i++){
            cin>>a[i];
            if(a[i]){
                if(!start) start=1;
            }
            else{
                if(start){
                    intervals++;
                    start = 0;
                }
            }
        }
        if(start) intervals++;

        intervals = intervals>2? 2: intervals;
        cout<<intervals<<"\n";
    }
}