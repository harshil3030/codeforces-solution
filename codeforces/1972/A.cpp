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
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    int k = n-1;
    int ans = -1;
    auto test = [&](int ind) {
        int j = n-1;
        for (int i = ind; i >= 0; i--) {
            if (b[j] < a[i]) {
                return false;
            }
            j--;
        }
        return true;
    };
    for (int i = n-1; i >= 0; i--) {
        if (b[k] >= a[i]) {

            if(test(i)) {
              ans = max(ans, i);   
            }
        }
    }   
    cout << n - (ans + 1) << "\n";

}
