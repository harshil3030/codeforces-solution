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
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    int  flg = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i-1]) {
            flg = 0;
            break;
        }
    }
    if (flg == 1) {
        cout << "YES\n";
        return;
    }
    if (k == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    
}
