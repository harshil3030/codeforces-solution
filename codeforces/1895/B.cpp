#include<bits/stdc++.h>
using namespace std;
int t = 0;
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
    int n; cin >> n;
    vector<int> v(2*n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i] = {v[2*n-1-i], v[i]};
    }
    int dis = abs(vp[0].first - vp[n-1].first) + abs(vp[0].second - vp[n-1].second);
    cout << dis << "\n";
    for (int i = 0; i < n; i++) {
        cout << vp[i].first << " " << vp[i].second << "\n";
    }
}


