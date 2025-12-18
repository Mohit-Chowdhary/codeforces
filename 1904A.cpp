#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        set<pair<int,int>> st;
        int count = 0;
        for(int i=-1;i<2;i+=2){
            for(int j=-1;j<2;j+=2){
                int placement1 = x1+(a*i),placement2 = y1 + (b*j);
                if( ((abs(placement1-x2) == a && abs(placement2-y2)==b) || (abs(placement1-x2) == b && abs(placement2-y2)==a)) && st.find({placement1,placement2}) == st.end()){
                    st.insert({placement1,placement2});
                    count++;
                }
            }
        }
        for(int i=-1;i<2;i+=2){
            for(int j=-1;j<2;j+=2){
                int placement1 = x1+(b*i),placement2 = y1 + (a*j);
                if( ((abs(placement1-x2) == a && abs(placement2-y2)==b) || (abs(placement1-x2) == b && abs(placement2-y2)==a)) && st.find({placement1,placement2}) == st.end() ){
                    st.insert({placement1,placement2});
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}