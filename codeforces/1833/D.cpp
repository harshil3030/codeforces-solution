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

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i].first = v[i];
        vp[i].second = i;
    }

    sort(vp.begin(), vp.end());
    int in1 = vp[n-1].second;
    int ele1 = vp[n-1].first;
    if(n == 1) {
        cout << v[0] << " "; cout << "\n";
        return;
    }
    int in2 = vp[n-2].second;
    int ele2 = vp[n-2].first;
    int left, right;

    if (in1 == 0) {
        if (in2 == n-1) {
            int extraind = in2;
            left = extraind, right = extraind;
        } else {
            int extraind = in2 - 1;
            right = extraind;
            left = extraind;
            int i = 0; extraind--;
            while (i < extraind) {
                if (v[i] > v[extraind]) {
                    break;
                } else {
                    left--;
                    extraind--;
                }
            }
        }
    } else {
        if (in1 == n-1) {
            int extraind = in1;
            right = extraind;
            left = extraind;
            int i = 0; extraind--;
            while (i < extraind) {
                if (v[i] > v[extraind]) {
                    break;
                } else {
                    left--;
                    extraind--;
                }
            }
        } else {
            int extraind = in1 - 1;
            right = extraind;
            left = extraind;
            int i = 0; extraind--;
            while (i < extraind) {
                if (v[i] > v[extraind]) {
                    break;
                } else {
                    left--;
                    extraind--;
                }
            }
        }
    }

    for (int i = right + 1; i < n; i++) cout << v[i] << " ";
    for (int i = right; i >= left; i--) cout << v[i] << " ";
    for (int i = 0; i < left; i++) cout << v[i] << " ";
    cout << "\n";
}   