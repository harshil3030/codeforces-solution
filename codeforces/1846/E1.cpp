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
    auto bin_expo = [&] (long long a, int b) {
        long long ans = 1;
        while (b > 0) {
            if (b % 2) {
                ans = ans * a;
            } b /= 2;
            a = a * a;
        }
        return ans;
    };
    for (long long k = 2; k <= 100000; k++) {
        long long mn = 1 + k + (k * k);
        if (n < mn) {
            cout << "NO\n";
            return;
        } else {
            if (n == mn) {  
                cout << "YES\n";
                return;
            } else {
                long long diff = n - mn;
                for (int i = 3; i <= 999; i++) {
                    diff -= bin_expo(k, i);
                    if (diff == 0) {
                        cout << "YES\n";
                        return;
                    }else if (diff < 0) {
                        break;
                    }
                }
            }
        }
    }
}
