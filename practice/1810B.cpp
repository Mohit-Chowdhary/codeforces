#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;

        if(n%2 == 0){
            cout<<-1<<"\n";
        }
        else{
            vector<int> a;
            while(n>1){
                if( (n+1)%4==0 ){
                    a.push_back(2);
                    n-=1;
                    n/=2;
                }
                else{
                    a.push_back(1);
                    n+=1;
                    n/=2;
                }
            }
            cout<<a.size()<<"\n";
            for(int i = a.size()-1; i>=0; i--){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
}