#include <bits/stdc++.h>

using namespace std;

void toh(int n, int from, int aux, int to){
    if(n==0) return;

    toh(n-1,from,to,aux);
    cout<<from<<" "<<to<<"\n";
    toh(n-1,aux,from,to);
}

int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    toh(n,1,2,3);
}