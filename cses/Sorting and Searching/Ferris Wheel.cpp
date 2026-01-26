#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    int i = 0, j = n-1;
    int count = 0;
    while(i<=j){
        if(i == j && a[i]<=k) count++;   
        else if(a[i]+a[j]<= k) {
            i++;
            count++;
        }
        else if(a[j]<=k) {
            count++;
        }
        j--;
    }

    cout<<count<<endl;

}
