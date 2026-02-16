#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    char c;
    cin>>n>>c;

    string s;
    cin>>s;
    if(c=='g'){
        cout<<"0\n";
        return;
    }

    string s2=s;
    s2+=s;

    int size = -1;

    int eq = 0;
    int dist = 0;
    for(int i=0;i<2*n;i++){
        if(s2[i] == c && !eq){
            eq=1;
            dist = 1;
        }
        else if(s2[i] == 'g' && eq){
            size = max(size,dist);
            dist=0;
            eq=0;
        }
        else if(s2[i] != 'g' && eq) dist++;
    }

    cout<<((size==-1)?n-1:size)<<"\n";
}

int main(){
    int tt;
    cin>>tt;

    while(tt--){
        solve();
    }
}
