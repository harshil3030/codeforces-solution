#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
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
//sol.
void solve() {
    int n; cin >> n;
    vector<int> a(n); vector<int> b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<pair<int, int>> sm(n);
    int score1 = 0, score2 = 0;
    for (int i = 0; i < n; i++) {
        sm[i].first = a[i] + b[i];
        sm[i].second = i;    
    }
    sort(sm.rbegin(), sm.rend());
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int in = sm[i].second;
            a[in]--;
            b[in] = 0;
            score1 += a[in];
        } else {
            int in = sm[i].second;
            b[in]--;
            a[in] = 0;
            score2 += b[in];
        }
    }
    cout << score1 - score2 << "\n";
}
