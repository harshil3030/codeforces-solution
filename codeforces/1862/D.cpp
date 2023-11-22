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
    int s = 2;
    int e = min((int)2e9,n);
    if (n == 1) {
        cout << 2 << "\n";
        return;
    }
    int x = 0;
    while (s <= e) {
        int mid = s + (e - s)/2;
        if (mid * (mid - 1)/2 <= n) {
            x = mid;
            s = mid+1;
        } else e = mid-1;
    }
    int res = x * (x - 1)/2;
    int ans = (n -  (x * (x - 1)/2)) + x;
    cout << ans << "\n";
}
