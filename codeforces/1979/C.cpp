#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int lcm(int x, int y) {return (x*y/__gcd(x,y));}

void solve() {
 int n;
 cin >> n;
 vector<int> v(n);
 for(auto &x: v) cin >> x;
 int l = v[0];
 for(int i = 0; i < n ;i++) {
    l = lcm(l, v[i]);
 }
 int sm = 0;
 for(int i= 0; i <n ;i++) {
    sm += l/v[i];
 }
 if(sm >= l) {
    cout << -1 << "\n";
    return;
 }
 for(auto &x : v) cout << l/x << " ";
 cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}