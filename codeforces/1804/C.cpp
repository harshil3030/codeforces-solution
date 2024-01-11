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
    int n,x,p; cin >> n >> x >> p;
    int point = (n - x);
    int i = 1;
    if (x == 0) {
        for (int i = 1; i <= min(2*n,p); i++) {
            if ((i*(i + 1)/2) % n == 0) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
        return;
    }
    while (i <= 2*n && i <= p) {
        int tot = (i * (i + 1))/2;
        if (tot % n == point) {
            cout << "YES\n";
            return;
        }
        i++;
    }
    cout << "NO\n";

}
