#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void dfs(int v, int p, vector<vector<int>> &dp, vector<vector<int>> &li, vector<vector<int>> &a) {
    for(auto &child : li[v]) {
        if (child == p) continue;
        dfs(child, v, dp, li, a);
        dp[v][0] += max(abs(a[child][0] - a[v][0])+ dp[child][0], abs(a[v][0] - a[child][1]) + dp[child][1]);
        dp[v][1] += max(abs(a[v][1] - a[child][0]) + dp[child][0], abs(a[child][1] - a[v][1]) + dp[child][1]);
    }
}


void solve() {
    int n;
    cin >> n;
    int m = n-1;
    vector<vector<int>> a(n, vector<int> (2));
    for(int i = 0; i < n; i++) {
        int av, au;
        cin >> av >> au;
        a[i][0] = av;
        a[i][1] = au;
    }
    vector<vector<int>> li(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        li[n1].push_back(n2);
        li[n2].push_back(n1);
    }
    vector<vector<int>> dp(n, vector<int> (2, 0));
    dfs(0, -1, dp, li, a);
    cout << max(dp[0][0], dp[0][1]) << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}