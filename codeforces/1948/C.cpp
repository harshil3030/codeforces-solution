#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

void solve() {
 int n;
 cin >> n;
 string s,t;
 cin >> s >> t;
 bool ok = true;
 vector<vector<int>> dp(n, vector<int> (2, 0));
 if (s[1] == '>') dp[1][0] = 1;
 if (t[0] == '>') dp[0][1] = 1;
 for (int i = 3; i < n; i+=2) {

    if (t[i-3] == '>')
    dp[i-1][1] = dp[i-3][1];

    if(s[i-2] == '>') 
    dp[i-1][1] = dp[i-1][1] | dp[i-2][0];
    
    if (s[i-2] == '>')
    dp[i][0] = dp[i-2][0];

    if (t[i-1] == '>') {
        dp[i][0] = dp[i][0] | dp[i-1][1];
    }
 }  

 if (dp[n-2][1] && t[n-2] == '>') {
    cout << "YES\n";
 }else {
    cout << "NO\n";
 }


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}