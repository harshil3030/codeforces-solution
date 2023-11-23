#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define int ll
const int mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
// typedef long long int int;

void solve();
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
    solve();
    return 0;
}

//sol.

void solve() {
    // t++;
    int n; cin >> n;    string s; cin >> s;
    
    // if (t == 82) {
    //     string print = to_string(n);
    //     print += "|";
    //     print += s;
    //     cout << print << "\n";
    //     return;
    // }

    if (n % 2) {
        cout << "-1" << "\n";
        return;
    }
    int zeros = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros++;
        else ones++;
    }
    if (zeros != ones) {
        cout << -1 << "\n";
        return;
    }
    int moves = 0;
    int i = 0;
    int j = n - 1;
    vector<int> movesv;
    while (i < j && moves <= 300) {
        if (s[i] != s[j]) {
            i++; j--;
        }else {
            if (s[i] == '0') {
                movesv.push_back(j+1);
                s = s.substr(0,j+1) + "01" + s.substr(j+1);
                j += 1; i++;
            }else {
                movesv.push_back(i);
                s = s.substr(0,i) + "01" + s.substr(i);
                // cout << "inner : " << s << "\n";
                i += 1;
                j += 1;
                // cout << i << " " << j << "\n";
            }
            moves++;
        }
    }
    // cout << s << "\n";
    cout << movesv.size() << "\n";
    for (auto &x : movesv) {
        cout << x << " ";
    } cout << "\n";

}
