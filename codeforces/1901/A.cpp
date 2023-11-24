#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define int ll
#define ff first
#define ss second
const int mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}

//sol.
void solve() {
    int n, x; cin >>n >> x;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int mx = (2*(x - v[n-1]));
    v.insert(v.begin(), 0);
    for (int i = 1; i <= n; i++) {
        mx = max(mx,  v[i] - v[i-1]);
    }
    cout << mx << "\n";
}
