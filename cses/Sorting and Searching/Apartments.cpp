#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n; i++){
        cin>>a[i];
    }
    for(int i=0;i<m; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0;
    int j=0;
    int count = 0;

    while(i<n && j<m){
        int diff = a[i] - b[j];
        if( diff>= -k && diff<=k){
            count++; i++; j++;
        }
        else if(diff<0){
            i++;
        }
        else{
            j++;
        }
    }

    cout<<count<<endl;

}
