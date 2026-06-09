    /*
        author: Mohit-Chowdhary
    */

    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    const int MOD = 1e9+7;
    #define all(x) (x).begin(), (x).end()


    void solve(){
        ll n,k; cin>>n>>k;

        string s; cin>>s;

        vector<int> st;
        vector<int> used(n);

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push_back(i);
            }
            else{
                if(!st.empty()){
                    int j = st.back();
                    st.pop_back();

                    used[i]=2;
                    used[j]=1;
                }
            }
        }
        string a;
        vector<int> count;
        int counto = 0;
        int countc = 0;

        vector<int> og;

        for(int i=0;i<n;i++){
            if(used[i]){
                a += s[i];
                og.push_back(i);
                if(used[i] == 2) count.push_back(countc) ;
                else count.push_back(counto);
            }
            if(s[i] == '('){
                countc = 0; counto++;
            }
            else{
                counto = 0; countc++;
            }
        }

        countc = 0, counto = 0;

        int j = count.size()-1;

        // for(int i=n-1;i>=0; i--){
        //     if(used[i]){
        //         if(used[i] == 2) count[j--]+=(countc) ;
        //         else count[j--]+=(counto);
        //     }
        //     if(s[i] == '('){
        //         countc = 0; counto++;
        //     }
        //     else{
        //         counto = 0; countc++;
        //     }
        // }


        cout<<a;
        cout<<endl;
        for(auto x: count) cout<<x<<" ";
        cout<<endl;

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
