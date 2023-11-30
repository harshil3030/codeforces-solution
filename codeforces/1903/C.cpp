#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1e9+7;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
void solve();
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------
void solve () {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int pref[n+1]; pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + v[i-1];
    int sm = 0; int mul = 1;
    for (int i = 0; i < n; i++) {  
        sm += v[i] * mul;
        if (pref[n] - pref[i+1] >= 0)  {
            mul++;
        }
    }
    cout << sm << "\n";
}
