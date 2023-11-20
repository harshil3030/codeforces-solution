#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
// #define ff    first
// #define ss    second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
void solve() {
    long long n; cin >> n;
    long long s = 2;
    long long e = min((ll)2e9,n);
    if (n == 1) {
        cout << 2 << "\n";
        return;
    }
    long long x = 0;
    while (s <= e) {
        long long mid = s + (e - s)/2;
        if (mid * (mid - 1)/2 <= n) {
            x = mid;
            s = mid+1;
        } else e = mid-1;
    }
    long long res = x * (x - 1)/2;
    long long ans = (n -  (x * (x - 1)/2)) + x;
    cout << ans << "\n";
}
