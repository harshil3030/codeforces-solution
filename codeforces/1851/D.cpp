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
    vector<long long> v(n - 1);
    for (auto &x : v) cin >> x;
    if (n <= 2) {
        if ((v[0] == 1 || v[0] == 3 || v[0] == 2)) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    if (v[n-2] > (n*(n+1))/2) {
        cout << "NO\n";
        return;
    }
    if (v[n-2] != (n * (n + 1))/2) {
        v.push_back((n*(n+1))/2);
        map<long long, long long> mp;
        mp[v[0]]++;
        for (int i = 1; i < n; i++) {
            mp[v[i] - v[i - 1]]++;
        }
            for (int i = 1; i <= n; i++) {
                if (mp.find(i) == mp.end()) {
                    cout << "NO\n";
                    return;
                }
            }
        if (mp.size() != n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } else {
        map<long long, long long> mp;
        mp[v[0]] += 1;
        for (int i = 1; i < n - 1; i++) {
            mp[v[i] - v[i - 1]] += 1;
        } 
        long long mis1 = 0, mis2 = 0; long long extra = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp.count(i)) {
                if (!mis1) mis1 = i;
                else if (!mis2) mis2 = i; 
            }
        }
        int flg = 0;
        for (auto &x : mp) {
            if (x.second > 1) flg++;
            if (x.second > 2) flg += 2;
        }
        if (flg >= 2) {
            cout << "NO\n";
            return;
        }
        for (auto &x : mp) {
            if (x.second > 1 || x.first > n) {
                extra = x.first;
                break;
            }
        }
        if (!extra) {
            cout << "NO\n";
            return;
        }
        if (mis1 + mis2 == extra) {
            cout << "YES\n";
        }else cout << "NO\n";
    } 
}
