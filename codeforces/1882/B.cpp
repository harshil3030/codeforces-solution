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
    int n; cin >> n;
    set<int> s;
    set<int> st[n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int y; cin >> y;
            s.insert(y);
            st[i].insert(y);
        }
    }
    long long mx = 0;
    long long ans = 0;
    for (auto &x : s) {
        set<int> temp;
        for (int i = 0; i < n; i++) {
            if (st[i].find(x) != st[i].end()) {
                continue;
            }else {
                for (auto &y : st[i])
                temp.insert(y);
            }
        }
        mx = max(mx, (long long)temp.size());
    }
    cout << mx << "\n";
}
