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
//    int tt = 1; cin >> tt; while (tt--)
    solve();
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    vector<char> color(n);
    for (auto &x : v) cin >> x;
    for (auto &x : color) x = 'r';
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (color[i] == 'b') {
            if (v[i] == 1 || v[i] == 2) {
                color[i + 1] = 'b';
                v[i]--;
            }
        }else if (color[i] == 'r') {

            if (v[i] == 1 || v[i] == 2) {
                v[i]--;
                cnt++;
                color[i + 1] = 'b';
                color[i] = 'b';
            }else if (v[i] == 0) {
                if (v[i + 1] == 1 || v[i + 1] == 2) {
                    color[i] = 'b';
                    v[i + 1]--;
                }else {
                    color[i] = 'b';
                    cnt++;
                }
            }
        }
    }
    if (color[n-1] == 'r') {
        cnt++;
    }
    cout << cnt << "\n";
}
