#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve() {
    int n,k,d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    dp[0][0] = 1, dp[0][1] = 0;
    
    //0 -> means not having edge >= d
    //1 -> means having edge >= d
    
    
    //to calculate the dp!
    for(int sm = 0; sm <= n; sm++) {
        for(int i = 1; i <= k; i++) {

            if(i > sm) break;
            
            /*
                if taking the edge is >= d
                we can only calculate dp[sm][1].. 
                the dp[sm][0] is not possible so it will remain 0,
                because it could not take this edge 
            */
            
            if (i >= d) {
                add(dp[sm][1], dp[sm-i][1]);
                add(dp[sm][1], dp[sm-i][0]);
            } else {
                
                /*
                    if we can't take edge >= d
                    we can calculate the dp[sm][1] from dp[sm-i][1]
                    and dp[sm][0] from dp[sm-i][0]
                    
                    not other combinations 
                */
                
                add(dp[sm][0], dp[sm-i][0]);
                add(dp[sm][1], dp[sm-i][1]);
            }

        }
    }

    cout << dp[n][1] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}