// Problem: A. Vacations
// Contest: Codeforces - Codeforces Round 363 (Div. 1)
// URL: https://codeforces.com/problemset/problem/698/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;

int work(int ind, int prev, vector<int> &v, vector<vector<int>> &memo) {
    if (ind >= v.size()) return 0;
    
    if (memo[ind][prev] != -1) return memo[ind][prev];
    
    int ans = 0;
    if (v[ind] == 0) {
        ans += work(ind + 1,0,v,memo);
    } else if (v[ind] == 1) {
        if (prev == 1) ans = work(ind + 1, 0, v, memo);
        else ans = max(work(ind + 1,0,v,memo), work(ind + 1,1,v,memo) + 1);
    } else if (v[ind] == 2) {
        if (prev == 2) ans = work(ind + 1, 0, v, memo);
        else ans = max(work(ind + 1,0,v,memo), work(ind + 1,2,v,memo) + 1);
    } else {
        
        if (prev == 1) {
            ans = max(work(ind + 1, 2, v, memo) + 1,    
             work(ind + 1, 0, v, memo));
        } else if (prev == 2) {
            ans = max(work(ind + 1, 1, v, memo) + 1, 
            work(ind + 1, 0, v, memo));
        } else {
            ans = max(max(work(ind + 1, 0, v, memo), 
            work(ind + 1, 1, v, memo) + 1), work(ind + 1, 2, v, memo) + 1);
        }
    }
    
    return memo[ind][prev] = ans;
}
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for (auto &x : v) cin >> x;   
    vector<vector<int>> memo(n+1, vector<int> (4,-1));
    
    int ans = 0;
    if (v[0] == 0) {
        ans = max(work(1,0,v,memo), ans);
    } else if (v[0] == 1) {
        ans = max(work(1,0,v,memo), work(1,1,v,memo) + 1);    
    } else if (v[0] == 2) {
        ans = max(work(1,0,v,memo), work(1,2,v,memo) + 1);
    } else {
        ans = max(max(work(1,0,v,memo), work(1,1,v,memo) + 1), 
        work(1,2,v,memo) + 1);
    }
    
    // cout << ans << "\n";
    cout << n-ans << "\n";
}
