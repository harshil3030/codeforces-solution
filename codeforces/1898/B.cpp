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
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    // t++;
    // if (t == 77) {
    //     string s = to_string(n) + "|";
    //     for (int i = 0; i < n; i++) {
    //         s += to_string(v[i]) + "|";
    //     }
    //     cout << s << "\n";
    //     return;
    // }
    int last = v[n-1]; int op = 0;
    for (int i = n-2; i >= 0; i--) {
        if (v[i] > last) {
            op += v[i]/last;
            int grp = v[i]/last;
            if (v[i] % last == 0) op--;
            if (v[i] % last) {
                v[i]/=(grp + 1);
            }else v[i]/=grp;
        }
        last = v[i];
    }
    cout << op << "\n";
    
}
