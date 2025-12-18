#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;
        if(s=="first"){
            int n;
            cin>>n;
            int a[n];
            for(int i=0; i<n; i++) cin>>a[i];
            cout<<(char)n<<'q';
            for(int i=0; i<n; i++){
                cout<<(char)a[i]<<'a';
            }
            cout<<endl;
        }
        else{
            int m=0;
            for(int i=0; i<s.size(); i++){
                if(s[i]=='q' || s[i] == 'a'){
                    cout<<m<<' ';
                    m=0;
                }
                else(){
                    m*=10;
                    m+=(int)s[i];
                }
            }
            cout<<endl;
        }

    }

    return 0;
}
