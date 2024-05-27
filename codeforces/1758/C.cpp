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
 int n,x;
 cin >> n >> x;
 vector<int> p(n);
 p[n-1] = 1;
 p[0] = x;

if (x == n) {
    cout << p[0] << " ";
    for(int i = 2; i <= n-1; i++) {
        cout << i << " ";
    }
    cout << p[n-1] << "\n";
    return;
}

if (n % x != 0) {
    cout << -1 << "\n";
    return;
}

for(int i = 1; i <= n-2; i++) p[i] = i+1;

while (x <= n-2) {
    for(int i = x*2; i <= n; i += x) {
        if (n % i == 0) {
            p[x-1] = i;
            x = i;
            break;
        }
    }
}

// vector<int> tmp;
// int last = n;
// tmp.push_back(n);
// for(int i = n-1; i > x; i--) {
//     if (i % x == 0 && last % i == 0) {
//         tmp.push_back(i);
//         last = i;
//     }
// }
// reverse(tmp.begin(), tmp.end());
// int ind = x-1;
// int k = 0;
// while (ind <= n-2) {
//     p[ind] = tmp[k];
//     ind = tmp[k] - 1;
//     k++;
// }

 for(auto &x : p) cout << x << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}