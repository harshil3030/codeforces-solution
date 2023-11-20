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
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        if (x <= n) {
            v.push_back(x);
        }
    }
    map<long long, long long> mp;
    for (int i = 0; i < v.size(); i++) mp[v[i]]++;
    map<long long, long long> mxcnt;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) mxcnt[j] += mp[i];
    }
    long long mx = 0;
    for (auto &x : mxcnt) mx = max(mx, x.second);
    cout << mx << "\n";
}
