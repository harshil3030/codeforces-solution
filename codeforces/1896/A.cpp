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
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}

//sol.
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (auto &x : v) cin >> x;
    
    if (v[0] == 1) {
        cout << "YES\n";
    }else
    cout << "NO\n";
 }

    
    



