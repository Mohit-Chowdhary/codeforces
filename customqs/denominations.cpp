/*
# Cash Register Feasibility

You are given three distinct bill denominations:

d0, d1, d2

The cash register initially contains:

c0 bills of denomination d0
c1 bills of denomination d1
c2 bills of denomination d2

There are n customers arriving in order.

For each customer i, you are given:

cost[i] — the price of the item
pay[i] — the bill used for payment

It is guaranteed that:

pay[i] ∈ {d0, d1, d2}
pay[i] ≥ cost[i]

For every customer:

1. The payment bill is first added to the cash register.
2. The cashier must then return exactly:
   change = pay[i] - cost[i]

3. The change may be formed using any bills currently available in the register.
4. Bills given as change are removed from the register.

Determine whether it is possible to serve all customers in order.

Output YES if all customers can be served, otherwise output NO.

--Input Format--

d0 d1 d2

c0 c1 c2

n

cost1 pay1
cost2 pay2
...
costn payn

--Constraints--

1 ≤ n ≤ 100
d0 < d1 < d2
0 ≤ ci ≤ 100
pay[i] ∈ {d0,d1,d2}
pay[i] ≥ cost[i]

--Output Format--

Print: YES, if all customers can be served, otherwise print: NO

*/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    struct State {
        int i, a, b, c;

        bool operator==(const State& o) const {
            return i==o.i &&
                   a==o.a &&
                   b==o.b &&
                   c==o.c;
        }
    };

    struct Hash {
        size_t operator()(const State& s) const {
            size_t h = s.i;
            h = h * 131 + s.a;
            h = h * 131 + s.b;
            h = h * 131 + s.c;
            return h;
        }
    };

    int d[3];

    vector<pair<int,int>> customers;

    unordered_map<State,bool,Hash> memo;

    bool dfs(int idx, int a, int b, int c) {

        if(idx == (int)customers.size())
            return true;

        auto [cost, pay] = customers[idx];

        // receive payment first
        if     (pay == d[0]) a++;
        else if(pay == d[1]) b++;
        else                 c++;

        State cur{idx, a, b, c};
        if(memo.count(cur)) return memo[cur];

        int change = pay - cost;

        // try ALL combinations of bills that sum to change
        for(int x = 0; x <= a; x++) {
            int rem1 = change - x * d[0];
            if(rem1 < 0) break;

            for(int y = 0; y <= b; y++) {
                int rem2 = rem1 - y * d[1];
                if(rem2 < 0) break;

                for(int z = 0; z <= c; z++) {
                    int rem3 = rem2 - z * d[2];
                    if(rem3 < 0) break;

                    if(rem3 == 0) {  // exact change made
                        if(dfs(idx+1, a-x, b-y, c-z))
                            return memo[cur] = true;
                    }
                }
            }
        }

        return memo[cur] = false;
    }
    
    bool canServe(
        vector<int> denom,
        vector<int> initial,
        vector<pair<int,int>> cust
    ) {

        d[0] = denom[0];
        d[1] = denom[1];
        d[2] = denom[2];

        customers = cust;

        memo.clear();

        return dfs(
            0,
            initial[0],
            initial[1],
            initial[2]
        );
    }
};

int main() {
    Solution s;

    vector<int> denom = {1,5,10};
    vector<int> initial = {5,1,0};

    vector<pair<int,int>> cust = {
        {4,10},
        {7,10}
    };

    cout << (s.canServe(denom, initial, cust) ? "YES" : "NO");
}