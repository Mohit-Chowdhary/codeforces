#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio();
    int n;
    cin>>n;
    while(n>0){
        n--;

        string s1;
        cin>>s1;

        vector<int> digits;
        for (char c : s1) {
            digits.push_back(c - '0');
        }

        set<int> sa(digits.begin(), digits.end());

        vector<int> s(sa.begin(),sa.end());

        set<int> seen;
        vector<int> result;

        for (int digit : digits) {
            if (seen.find(digit) == seen.end()) {
                seen.insert(digit);
            } else {
                result.push_back(digit);
            }
        }

        sort(result.begin(), result.end());


        string final="";

        int i=10;

        while(i>0){
            i--;
            if(find(s.begin(), s.end(), i)!= s.end()){
                final+=to_string(i);
            }
            else{
                for(int j=0;j<=result.size();j++){
                    if(result[j]>=i){
                        final+=to_string(result[j]);
                        result.erase(result.begin() + j);
                        break;
                    }
                }
            }
        }

        cout<<final<<"\n";
    }

}
