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
    string s; cin >> s;
    int countopen = 0;
    int countclose = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') countopen++;
        else countclose++;
    }
    if (countopen != countclose) {
        cout << -1 << "\n";
        return;
    }
    char cur = s[0]; countopen = 0, countclose = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == cur) {
            if (cur == '(') { 
                countopen++;
                ans[i] = 1;
            } 
            else {
                countclose++;
                ans[i] = 2;
            }
        }else {
            if (s[i] == ')') {
                if (countopen > 0) {
                    countopen--;
                    ans[i] = 1;
                }else {
                    cur = s[i];
                    countclose++;
                    ans[i] = 2;
                }
            } else {
                if (countclose > 0) {
                    countclose--;
                    ans[i] = 2;
                }else {
                    cur = s[i];
                    countopen++;
                    ans[i] = 1;
                }
            }
        }
    }
    int mx = *max_element(ans.begin(), ans.end());
    int mn = *min_element(ans.begin(), ans.end());
    if (mn == mx) {
        cout << 1 << "\n";
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        } cout << "\n";
        return;
    }
    cout << mx << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
