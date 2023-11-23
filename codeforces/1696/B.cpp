#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define int ll
const int mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
// typedef long long int int;

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
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int freq = 0;
    v.push_back(0);
    if (n == 1) {
        if (v[0] == 0) {
            cout << 0 << "\n";
        }else cout << 1 << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0 && v[i - 1] != 0) {
            freq++;
        }
    }
    if (freq == 0) {
        cout << 0 << "\n";
    }else if (freq == 1){    
        cout << 1 << "\n";
    }else cout << 2 << "\n";

}
