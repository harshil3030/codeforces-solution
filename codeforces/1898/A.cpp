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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a++;
        else b++;
    }
    if (b == k) {
        cout << 0 << "\n";
        return;
    }
    if (b < k) {
        int req = k-b; int in = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') req--;
            if (req == 0) {
                in = i + 1;
                break;
            }
        }
        cout << 1 << "\n";
        cout << in << " " << 'B' << "\n";
    }else {
        int req = b-k;
        int in = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') req--;
            if (req == 0) {
                in = i + 1;
                break;
            }
        }
        cout << 1 << "\n";
        cout << in << " " << "A" << "\n";
    }
}
