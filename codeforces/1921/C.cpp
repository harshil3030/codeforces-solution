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
    int n,f,a,b; cin >> n >> f >> a >> b;
    vector<int> v;
    v.push_back(0);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((v[i] - v[i-1]) * a > b) ans += b;
        else ans += (v[i] - v[i-1]) * a;
    }

    if (ans < f) {
        cout << "YES\n";
    }else cout << "NO\n";
}
