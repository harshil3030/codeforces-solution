#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
       int n,k; cin >> n >> k;
       string s,t; cin >> s >> t;

       map<char,int> mp1,mp2;
       for (auto &x : s) mp1[x] += 1;
       for (auto &x : t) mp2[x] += 1;
       if (mp1 != mp2) {
            cout << "NO\n";
            return;
       }

       if (k > n) {
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
            return;
       }
       int far = k;
       int rest = n - k;
       for (int i = rest; i < far; i++) {
            if (s[i] != t[i]) {
                cout << "NO\n";
                return;
            }
       }

       cout << "YES\n";

}
