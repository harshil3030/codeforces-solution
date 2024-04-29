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
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int q; cin >> q;
    map<int, int> freq;
    for(auto &x : v) freq[x]++;

    auto rootFind = [&](int tar) -> int {
        int lo = 0, hi = 1e10;
        int ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            ans = mid;
            if (mid * mid == tar) return mid;
            if (mid * mid < tar) {
                lo = mid + 1;   
            }
            else hi = mid - 1;
        }
        return ans;
    };
    while (q--) {
        int x,y; cin >> x >> y;
        if ((x*x - 4*y) < 0) {
            cout << 0 << " ";
            continue;
        }
        int root1 = (x + rootFind((x*x - 4*y)))/2;
        int root2 = (x - rootFind((x*x - 4*y)))/2;
        if(root1 + root2 != x || root1 * root2 != y) {
            cout << 0 << " ";
            continue;
        }

        if (root1 == root2) {
            cout << (freq[root1] * (freq[root1] - 1))/2 << " ";
            continue;
        }
        cout << freq[root1]*freq[root2] << " ";
    } cout << "\n";
}
