#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
// #define int long long
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
// typedef long long int int;

void solve();
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tt; cin >> tt;  while (tt--)
    solve();
    return 0;
}

//sol.
void solve() {
    // t++;
    int n; long long k; cin >> n >> k;
    vector<long long> f(n);
    vector<long long> h(n);
    for (auto &x : f) cin >> x;
    for (auto &x : h) cin >> x;
    // if (t == 588) {
    //     string s = "";
    //     s = to_string(n) + "|" + to_string(k) + "|";
    //     for (int i = 0; i < n; i++) {
    //         s += to_string(f[i]) + "|";
    //     }
    //     for (int i = 0; i < n; i++) {
    //         s += to_string(h[i]) + "|";
    //     }
    //     cout << s << "\n";
    // }
    long long len = 0;
    if (n == 1) {
        if (f[n-1] <= k) {
            cout << 1 << "\n";
        } else cout << 0 << "\n";
        return;
    }
    
    long long mn = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] <= k) {
            mn = 1; break;
        }
    }

    long long mx = 0;
    long long collect = 0; int flg = 0;
    for (int i = 0; i < n - 1; i++) {
        if (h[i] % h[i + 1] == 0 && collect + f[i] <= k) {
            len++;
            collect += f[i]; flg = 1;
        } else if (h[i] % h[i + 1] != 0){
            if (collect + f[i] <= k && flg) {
                len++;
                mx = max(mx, len);
                flg = 0;
            }
            len = 0;
            collect = 0;
        } else {
            int j = i - len;
            while (collect + f[i] > k && j < i) {
                len--;
                collect -= f[j];
                j++;
            }
            if (collect + f[i] <= k) {
                len++;
                collect += f[i];
            } else {
                len = 0;
                collect = 0;
            }
        }

        mx = max(mx, len);
    }
    if (flg == 1 && collect + f[n - 1] <= k) {
        len++;
        mx = max(mx, len);
    }

    cout << max(mx,mn) << "\n";
}
