/*
    author: Mohit-Chowdhary
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];

vector<int> a;
vector<pair<int,int>> maxdist;
vector<vector<bool>> invalid;

int cnt = 0;

void count(int k,vector<bool>& row,vector<bool>& col, vector<bool> &diag1, vector<bool> &diag2){
    if(k==8){
        cnt++;
        return;
    }


    for(int j=0; j<8; j++){
        if(invalid[k][j] || row[j] || diag1[k+j] || diag2[7+k-j]) continue;

        row[j]=true;
        diag1[k+j]=true;
        diag2[7+k-j]=true;

        count(k+1,row,col,diag1,diag2);
        
        row[j]=false;
        diag1[k+j]=false;
        diag2[7+k-j]=false;
    }
}

void solve(){
    int n = 8;
    invalid.resize(n,vector<bool>(n,false));
    vector<bool> col(n,false);
    vector<bool> row(n,false);
    vector<bool> diag1(2*n-1,false);
    vector<bool> diag2(2*n-1,false);

    /*
        ASSUME N = 4

        0    1    2    3
        0 X    X    X    X
        1 X    X    X    X
        2 X    X    X    X
        3 X    X    X    X

        DIAG1 = i+j

        DIAG2 if we see the i is high priority than j

        so its like range of i-j => [3,-3]

        to normalize its n+i-j-1 =>[6,0]

        nice

        it is not that the queens are placed, but the squares themselves not to be used there
    */

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin>>c;

            if(c == '*'){
                invalid[i][j] = true;
            }
        }
    }

    count(0,row,col,diag1,diag2);

    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin>>tt;

    while(tt--){
        solve();
    }
}
