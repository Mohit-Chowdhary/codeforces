#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin>>a;
        vector<int> n(a);
        unordered_map<int,vector<int>> freq;

        for(int i=0;i<a;i++){
            cin>>n[i];
            freq[n[i]].push_back(i);
        }
        unordered_set<int> q(n.begin(),n.end());
        long long sum=0;

        unordered_map<int,int> m;

        for(int i: q){
            int freq=count(n.begin(),n.end(),i);
            m[i]=freq;
            if(freq%i!=0){
                sum=-1;
                break;
            }

            sum+=freq;
        }
        if(sum!=a || sum==-1){
            cout<<-1<<endl;
            continue;
        }

        vector<int> finalArr(a,0);

        int num=1;

        for(auto &[f,l]:freq){
            int temp=0;
            for(int m=0;m<l.size();m++){
                temp++;
                finalArr[l[m]]=num;
                if(temp==f){
                    num++;
                    temp=0;
                }
            }
        }

        for(int i=0;i<a;i++){
            cout<<finalArr[i]<<" ";
        }
        cout<<endl;


    }
    return 0;
}
