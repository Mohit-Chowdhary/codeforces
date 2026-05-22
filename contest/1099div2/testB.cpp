#include <bits/stdc++.h>
using namespace std;

// ██████╗ ██╗███████╗███████╗      ██████╗ ██████╗ ██████╗ ██╗███╗   ██╗ ██████╗
// ██╔══██╗██║╚══███╔╝╚══███╔╝     ██╔════╝██╔═══██╗██╔══██╗██║████╗  ██║██╔════╝
// ██████╔╝██║  ███╔╝   ███╔╝      ██║     ██║   ██║██║  ██║██║██╔██╗ ██║██║  ███╗
// ██╔══██╗██║ ███╔╝   ███╔╝       ██║     ██║   ██║██║  ██║██║██║╚██╗██║██║   ██║
// ██║  ██║██║███████╗███████╗     ╚██████╗╚██████╔╝██████╔╝██║██║ ╚████║╚██████╔╝
// ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝      ╚═════╝ ╚═════╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝

/*---SHORTCUTS---*/
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define sz(x) (int)(x.size())
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define debug(x) cerr << #x << " = " << x << endl;

const int mod = 1e9+7;
const int INF = 1e18;


/* 



*/ 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

int mx=INT_MIN;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]>a[i+1])
        {
            mx=max(mx,a[i]-a[i+1]);
        }
        
    }
    if(mx==0){
    yes;
    return;
    }

    for (int i = 0; i < n-1; i++)
    {
        if(a[i]>a[i+1])
        {
            a[i+1]+=mx;
        }
    }
    if(is_sorted(a.begin(),a.end()))yes;
    else no;
   
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--) solve();
}