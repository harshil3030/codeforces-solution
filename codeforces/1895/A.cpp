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
    int x, y, k; cin >> x >> y >> k;
    if (y - x > k) {
        int add = y - x - k;
        cout << y + add << "\n";
    }else {
        cout << max(x,y) << "\n";
    }
}


