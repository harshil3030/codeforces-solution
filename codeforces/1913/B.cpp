#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}
//-----------------------------------------------------------------------
void solve() {
    string s; cin >> s;
    vector<int> in1;
    vector<int> in2;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') in1.push_back(i);
        else in2.push_back(i);
    }
    int cnt = 0;int l = 1; int k = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (in2.size() >= k) {
                k++;
                cnt++;
            } else {
                break;
            }
        } else {
            if (in1.size() >= l) {
                l++;
                cnt++;
            } else {
                break;
            }
        }
    }

    cout << n-cnt << "\n";
}